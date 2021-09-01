#include "Controller.hpp"

Controller::Controller(View *view, Generator *generator) {
	this->view = view;
	this->generator = generator;
	time = 0.0;
	room = 1;
	player = new Player (0, view->getGameHeight()-1);
	collisions = new Collisions(player);
	h = new HardEnemy(view->getGameWidth()-1, view->getGameHeight()-1);
	m = new MediumEnemy(10, view->getGameHeight()-5);
	e = __null;
}

void Controller::run() {
	bool quit = false;
	this->initSetup();

	do {
		
		// DATA MANAGEMENT
		int input = view->getKeyboardInput();
		switch (input) {
			case 'q':
				quit = true;
				break;
			case 'e':
				// TODO: error with x of shoot
				player->shoots(time);
				break;
		}

		player->move(input, view->getGameWidth(), view->getGameHeight(), time,
					Platform::checkPlatformAbove(generator->getPlatforms(), generator->getNumberPlatforms(), player->getX(), player->getY()), 
					Platform::checkPlatformBelow(generator->getPlatforms(), generator->getNumberPlatforms(), player->getX(), player->getY()));
		h->follow(player->getX(), player->getY(), time,
					Platform::checkPlatformAbove(generator->getPlatforms(), generator->getNumberPlatforms(), h->getX(), h->getY()), 
					Platform::checkPlatformBelow(generator->getPlatforms(), generator->getNumberPlatforms(), h->getX(), h->getY()),
					view->getGameWidth(), view->getGameHeight());
		
		h->shoots(time, player->getX());

		m->follow(player->getX(), time,
					view->getGameWidth(), view->getGameHeight(),
					Platform::checkPlatformBelow(generator->getPlatforms(), generator->getNumberPlatforms(), m->getX()+1, m->getY()),
					Platform::checkPlatformBelow(generator->getPlatforms(), generator->getNumberPlatforms(), m->getX()-1, m->getY()));
		m->shoots(time, player->getX());
		
		if(e == __null) {
			e = new EasyEnemy(view->getGameWidth()-3, player->getY());
		}
		e->move(KEY_LEFT, view->getGameWidth(), view->getGameHeight(), time);

		// DRAW MAP
		view->clearWindow();
		view->drawBorders();
		view->printInfos(player->getName(), time, player->getLife(), player->getPoints(), room, player->getInvincibilityTimer(time), player->getMinigunTimer(time));

		// PRINT ENTITIES
		view->printObject(player->noOffsetX(), player->getY(), (char *)"%s", player->getSymbol(), 0, player->hasInvincibility());
		this->printShoots(player, 0);
		view->printObject(h->getX(), h->getY(), (char *)"%s", (char *) h->getSymbol(), player->getOffset());
		this->printShoots(h, player->getOffset());
		view->printObject(m->getX(), m->getY(), (char *)"%s", (char *) m->getSymbol(), player->getOffset());
		this->printShoots(m, player->getOffset());
		view->printObject(e->getX(), e->getY(), (char *)"%s", (char *) e->getSymbol(), player->getOffset());
		
		// CREATE AND PRINT PLATFORM
		for (int i = 0; i < generator->getNumberPlatforms(); i++) {
			Platform *platf = generator->getPlatform(i);
			view->printPlatform(platf->getX(), platf->getY(), platf->getLenght(), player->getOffset());
		}
		for (int i = 0; i < generator->getNumberBonuses(); i++) {
			Bonus *bonus = generator->getBonus(i);
			view->printObject(bonus->getX(), bonus->getY(), "%s", bonus->getSymbol(), player->getOffset());
		}

		// CHECKS
		player->checkBonusesTimer(time);
		this->checkRoomsGeneration();
		this->checkCollisions();

		view->update();
		time += (double)view->getDelay() / 1000;
	} while (!quit || player->getLife() > 0); // TODO: change || to &&

	view->printGameOver();
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
	if (room > generator->getCurrentRoom()) {
		generator->deleteRoom(room, LEFT_ROOM);
		generator->createRoom(room+1, RIGHT_ROOM, view->getGameWidth());
	} else if (room < generator->getCurrentRoom()) {
		generator->deleteRoom(room+1, RIGHT_ROOM);
		generator->createRoom(room, LEFT_ROOM, view->getGameWidth());
	}
}

void Controller::checkCollisions() {
	// PHYSICAL: Player - Enemies
		// TODO: WHILE for enemies and !hit (now only for hardEnemy)
		// TODO: when checking with easyenemy remove it if hit
	if (collisions->checkPhysicalDamage(h)) {
		if (!player->hasInvincibility() && (time - player->getLastDamageTime() > player->getCooldownDamage())) {
			player->decreaseLife(h->getAttack());
			player->setLastDamageTime(time);
		}
	}
	// Player - Enemies shoots
		// TODO: WHILE for enemies and !hit (now only for hardEnemy)
	if (collisions->checkPlayerShootsDamage(h)) {
		if (!player->hasInvincibility() && (time - player->getLastDamageTime() > player->getCooldownDamage())) {
			player->decreaseLife(h->getAttack());
			player->setLastDamageTime(time);
		}
	}

	// Shoots between player and enemies
		// TODO: WHILE for enemies (now only for hardEnemy)
	if (collisions->checkEnemyShootsDamage(h)) {
		h->decreaseLife(player->getAttack());	// TODO: check if dead
	}
	
	// - Spari - Piattaforme
	collisions->checkShootsPlatformsCollision(player, generator->getPlatforms(), generator->getNumberPlatforms());
		// TODO: WHILE for all enemies (now only for hardEnemy)
	collisions->checkShootsPlatformsCollision(h, generator->getPlatforms(), generator->getNumberPlatforms());

	// - EasyEnemies - Piattaforme o Muro
	if (collisions->checkEasyEnemyCollision(e, generator->getPlatforms(), generator->getNumberPlatforms())) {
		delete e;
		e = __null;
	}

	// Player - Bonuses
	for (int i = 0; i < generator->getNumberBonuses(); i++) {
		Bonus *bonus = generator->getBonus(i);
		if (collisions->checkBonusColission(bonus))
			this->checkBonusType(bonus);	// TODO: remove bonus from game
	}
}

void Controller::checkBonusType(Bonus *bonus) {
	switch (bonus->getBonusType()) {
		case INVINCIBILITY:
			player->setInvincibility(time);
			break;
		case LIFE:
			player->increaseLife(bonus->getBonusLife());
			break;
		case POINTS:
			player->increasePoints(bonus->getBonusPoints());
			break;
		case MINIGUN:
			player->setCooldownShoot(bonus->getMinigunCooldown(), time);
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
	generator->createRoom(room, LEFT_ROOM, view->getGameWidth());
	generator->createRoom(room+1, RIGHT_ROOM, view->getGameWidth());
	generator->createBonuses();
}