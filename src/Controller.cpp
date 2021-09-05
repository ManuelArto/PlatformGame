#include "Controller.hpp"

Controller::Controller(View *view, Generator *generator) {
	this->view = view;
	this->generator = generator;
	time = 0.0;
	room = 1;
	level = 1;
	player = new Player (0, view->getGameHeight()-1);
	collisions = new Collisions(player);
}

void Controller::run() {
	bool quit = false;
	this->initSetup();

	do {
		// INPUT MANAGEMENT
		int input = view->getKeyboardInput();
		switch (input) {
			case 'q':
				quit = true;
				break;
			case 'e':
				player->shoots(time);
				break;
		}

		// MOVEMENT AND SHOOTING
		player->move(input, view->getGameWidth(), view->getGameHeight(), time,
					Platform::checkPlatformAbove(generator->getPlatforms(), generator->getNumberPlatforms(), player->getX(), player->getY()),
					Platform::checkPlatformAbove(generator->getPlatforms(), generator->getNumberPlatforms(), player->getX(), player->getY()-1),
					Platform::checkPlatformBelow(generator->getPlatforms(), generator->getNumberPlatforms(), player->getX(), player->getY(), view->getGameHeight()),
					Platform::checkPlatformBelow(generator->getPlatforms(), generator->getNumberPlatforms(), player->getX(), player->getY()+1, view->getGameHeight()),
					Platform::checkPlatformRight(generator->getPlatforms(), generator->getNumberPlatforms(), player->getX(), player->getY()),
					Platform::checkPlatformLeft(generator->getPlatforms(), generator->getNumberPlatforms(), player->getX(), player->getY()));
		generator->initHardEnemyIterator();
		while(generator->hasNextHardEnemy()) {
			HardEnemy *h = generator->getNextHardEnemy();
			h->follow(player->getX(), player->getY(), time,
						Platform::checkPlatformAbove(generator->getPlatforms(), generator->getNumberPlatforms(), h->getX(), h->getY()), 
						Platform::checkPlatformAbove(generator->getPlatforms(), generator->getNumberPlatforms(), h->getX(), h->getY()-1), 
						Platform::checkPlatformBelow(generator->getPlatforms(), generator->getNumberPlatforms(), h->getX(), h->getY(), view->getGameHeight()),
						Platform::checkPlatformBelow(generator->getPlatforms(), generator->getNumberPlatforms(), h->getX(), h->getY()+1, view->getGameHeight()),
						Platform::checkPlatformRight(generator->getPlatforms(), generator->getNumberPlatforms(), h->getX(), h->getY()),
						Platform::checkPlatformLeft(generator->getPlatforms(), generator->getNumberPlatforms(), h->getX(), h->getY()),
						view->getGameWidth(), view->getGameHeight());
			h->shoots(time, player->getX());
		}
		generator->initMediumEnemyIterator();
		while(generator->hasNextMediumEnemy()) {
			MediumEnemy *m = generator->getNextMediumEnemy();
			m->follow(player->getX(), time,
						view->getGameWidth(), view->getGameHeight(),
						Platform::checkPlatformBelow(generator->getPlatforms(), generator->getNumberPlatforms(), m->getX()+1, m->getY(), view->getGameHeight()),
						Platform::checkPlatformBelow(generator->getPlatforms(), generator->getNumberPlatforms(), m->getX()-1, m->getY(), view->getGameHeight()),
						Platform::checkPlatformRight(generator->getPlatforms(), generator->getNumberPlatforms(), m->getX(), m->getY()),
						Platform::checkPlatformLeft(generator->getPlatforms(), generator->getNumberPlatforms(), m->getX(), m->getY()));
			m->shoots(time, player->getX(), player->getY());
		}
		generator->initEasyEnemyIterator();
		while(generator->hasNextEasyEnemy()) {
			EasyEnemy *e = generator->getNextEasyEnemy();
			e->move(KEY_LEFT, view->getGameWidth(), view->getGameHeight(), time);
		}

		// DRAW MAP
		view->clearWindow();
		view->drawBorders();
		view->printInfos(player->getName(), room, time, player->getLife(), player->getPoints(), level, player->getInvincibilityTimer(time), player->getMinigunTimer(time));

		// PRINT ENTITIES
		view->printObject(player->noOffsetX(), player->getY(), (char *)"%s", player->getSymbol(), 0, player->hasInvincibility(), player->isDamaged(time));
		this->printShoots(player, player->getOffset());
		generator->initHardEnemyIterator();
		while(generator->hasNextHardEnemy()) {
			HardEnemy *h = generator->getNextHardEnemy();
			view->printObject(h->getX(), h->getY(), (char *)"%s", (char *) h->getSymbol(), player->getOffset());
			this->printShoots(h, player->getOffset());
		}
		generator->initMediumEnemyIterator();
		while(generator->hasNextMediumEnemy()) {
			MediumEnemy *m = generator->getNextMediumEnemy();
			view->printObject(m->getX(), m->getY(), (char *)"%s", (char *) m->getSymbol(), player->getOffset());
			this->printShoots(m, player->getOffset());
		}
		generator->initEasyEnemyIterator();
		while(generator->hasNextEasyEnemy()) {
			EasyEnemy *e = generator->getNextEasyEnemy();
			view->printObject(e->getX(), e->getY(), (char *)"%s", (char *) e->getSymbol(), player->getOffset());
		}

		// PRINT PLATFORMS
		for (int i = 0; i < generator->getNumberPlatforms(); i++) {
			Platform *platf = generator->getPlatform(i);
			if (platf != __null)
				view->printPlatform(platf->getX(), platf->getY(), platf->getLenght(), player->getOffset());
		}
		// PRINT BONUSES
		p_bonus iter_bonus = generator->getBonuses();
		while (iter_bonus != __null) {
			Bonus *bonus = iter_bonus->bonus;
			view->printObject(bonus->getX(), bonus->getY(), "%s", bonus->getSymbol(), player->getOffset());
			iter_bonus = iter_bonus->next;
		}

		// CHECKS
		player->checkBonusesTimer(time);
		this->checkRoomsGeneration();
		this->checkCollisions();

		view->update();
		time += (double)view->getDelay() / 1000;
	} while (!quit || player->getLife() > 0); // TODO: change || to &&

	view->printGameOver(player->getPoints(), time);
	view->exitWindow();
}

void Controller::printShoots(Character *c, int offset) {
	p_shot tmp_shot, shot;
	shot = c->getShotHead();
	while(shot != __null) {
		view->printObject(shot->x, shot->y, (char *)"%s", (char *)"---", offset);
		tmp_shot = shot->next;
		c->updateShot(shot, view->getGameWidth()+offset);
		shot = tmp_shot;
	}
}

void Controller::checkRoomsGeneration() {
	room = (player->getOffset() / view->getGameWidth()) + 1;
	level = (room-1) / 2 + 1;
	if (room > generator->getCurrentRoom()) {
		generator->setCurrentRoom(room);
		generator->deleteRoom(LEFT_ROOM);
		generator->createRoom(room+1, RIGHT_ROOM, level, view->getGameWidth());
	} else if (room < generator->getCurrentRoom()) {
		generator->setCurrentRoom(room);
		generator->deleteRoom(RIGHT_ROOM);
		generator->createRoom(room, LEFT_ROOM, level, view->getGameWidth());
	}
	if (generator->canSpawnEasyEnemy(time))
		generator->spawnEasyEnemy(view->getGameWidth(), player->getOffset(), player->getY(), level, time);
}

void Controller::checkCollisions() {
	// PHYSICAL: Player - EasyEnemy
	generator->initEasyEnemyIterator();
	while(generator->hasNextEasyEnemy()) {
		EasyEnemy *e = generator->getNextEasyEnemy();
		if (collisions->checkEasyEnemyPhysicalDamage(e)) {
			if (!player->hasInvincibility() && !player->isDamaged(time)) {
				player->decreaseLife(e->getAttack());
				player->setLastDamageTime(time);
			}
			generator->removeEasyEnemy(e);
		}
	}

	// PHYSICAL: Player - Enemies
	generator->initHardEnemyIterator();
	while(generator->hasNextHardEnemy()) {
		HardEnemy *h = generator->getNextHardEnemy();
		if (collisions->checkPhysicalDamage(h)) {
			if (!player->hasInvincibility() && !player->isDamaged(time)) {
				player->decreaseLife(h->getAttack());
				player->setLastDamageTime(time);
			}
		}
	}
	generator->initMediumEnemyIterator();
	while(generator->hasNextMediumEnemy()) {
		MediumEnemy *m = generator->getNextMediumEnemy();
		if (collisions->checkPhysicalDamage(m)) {
			if (!player->hasInvincibility() && !player->isDamaged(time)) {
				player->decreaseLife(m->getAttack());
				player->setLastDamageTime(time);
			}
		}
	}

	// Player - Enemies shoots
	generator->initHardEnemyIterator();
	while(generator->hasNextHardEnemy()) {
		HardEnemy *h = generator->getNextHardEnemy();
		if (collisions->checkEnemyShoots(h)) {
			if (!player->hasInvincibility() && !player->isDamaged(time)) {
				player->decreaseLife(h->getAttack());
				player->setLastDamageTime(time);
			}
		}
	}
	generator->initMediumEnemyIterator();
	while(generator->hasNextMediumEnemy()) {
		MediumEnemy *m = generator->getNextMediumEnemy();
		if (collisions->checkEnemyShoots(m)) {
			if (!player->hasInvincibility() && !player->isDamaged(time)) {
				player->decreaseLife(m->getAttack());
				player->setLastDamageTime(time);
			}
		}
	}
	
	// Player shoots - Enemies
	generator->initHardEnemyIterator();
	while(generator->hasNextHardEnemy()) {
		HardEnemy *h = generator->getNextHardEnemy();
		if (collisions->checkPlayerShoots(h)) {
			h->decreaseLife(player->getAttack());
			if (h->getLife() <= 0) {
				player->increasePoints(h->getPoints());
				generator->removeHardEnemy(h);
			}
		}
	}
	generator->initMediumEnemyIterator();
	while(generator->hasNextMediumEnemy()) {
		MediumEnemy *m = generator->getNextMediumEnemy();
		if (collisions->checkPlayerShoots(m)) {
			m->decreaseLife(player->getAttack());
			if (m->getLife() <= 0) {
				player->increasePoints(m->getPoints());
				generator->removeMediumEnemy(m);
			}
		}
	}
	generator->initEasyEnemyIterator();
	while(generator->hasNextEasyEnemy()) {
		EasyEnemy *e = generator->getNextEasyEnemy();
		if (collisions->checkPlayerShoots(e)) {
			e->decreaseLife(player->getAttack());
			if (e->getLife() <= 0) {
				player->increasePoints(e->getPoints());
				generator->removeEasyEnemy(e);
			}
		}
	}
	
	// Spari - Piattaforme
	collisions->checkShootsPlatformsCollision(player, generator->getPlatforms(), generator->getNumberPlatforms());
	generator->initHardEnemyIterator();
	while(generator->hasNextHardEnemy()) {
		HardEnemy *h = generator->getNextHardEnemy();
		collisions->checkShootsPlatformsCollision(h, generator->getPlatforms(), generator->getNumberPlatforms());
	}
	generator->initMediumEnemyIterator();
	while(generator->hasNextMediumEnemy()) {
		MediumEnemy *m = generator->getNextMediumEnemy();
		collisions->checkShootsPlatformsCollision(m, generator->getPlatforms(), generator->getNumberPlatforms());
	}

	// EasyEnemies - Piattaforme o Muro
	generator->initEasyEnemyIterator();
	while(generator->hasNextEasyEnemy()) {
		EasyEnemy *e = generator->getNextEasyEnemy();
		if (collisions->checkEasyEnemyCollision(e, generator->getPlatforms(), generator->getNumberPlatforms()))
			generator->removeEasyEnemy(e);
	}

	// Player shoots - Enemies shoots
	generator->initHardEnemyIterator();
	while(generator->hasNextHardEnemy()) {
		HardEnemy *h = generator->getNextHardEnemy();
		collisions->checkShootsCollision(h);
	}
	generator->initMediumEnemyIterator();
	while(generator->hasNextMediumEnemy()) {
		MediumEnemy *m = generator->getNextMediumEnemy();
		collisions->checkShootsCollision(m);
	}
	
	// Player - Bonuses
	p_bonus iter_bonus = generator->getBonuses();
	while (iter_bonus != __null) {
		Bonus *bonus = iter_bonus->bonus;
		iter_bonus = iter_bonus->next;
		if (player->getX() == bonus->getX() && player->getY() == bonus->getY()) {
			this->checkBonusType(bonus);
			generator->deleteBonus(bonus);
		}
	}
}

void Controller::checkBonusType(Bonus *bonus) {
	switch (bonus->getBonusType()) {
		case INVINCIBILITY:
			player->setInvincibility(time, bonus->getInvincibilityTimer());
			break;
		case LIFE:
			player->increaseLife(bonus->getBonusLife());
			break;
		case POINTS:
			player->increasePoints(bonus->getBonusPoints());
			break;
		case MINIGUN:
			player->setCooldownShoot(bonus->getMinigunCooldown(), time, bonus->getMinigunTimer());
			break;
	}
}

void Controller::initSetup() {
	view->createWindow();
	view->printLoadingGame();
	view->askName(player->getName(), player->getMaxNameLenght());
	this->initGeneration();
}

void Controller::initGeneration() {
	generator->createRoom(room, LEFT_ROOM, level, view->getGameWidth());
	generator->createRoom(room+1, RIGHT_ROOM, level, view->getGameWidth());
}