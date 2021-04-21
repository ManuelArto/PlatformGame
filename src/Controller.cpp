#include "Controller.hpp"

Controller::Controller(View *view, Generator *generator) {
	this->view = view;
	this->generator = generator;
	time = 0;
	room = 1;
	player = new Player (0, view->getGameHeight()-1);
	h = new HardEnemy(view->getGameWidth()-1, view->getGameHeight()-1);
}

void Controller::run() {
	bool quit = false;
	view->createWindow();
	view->askName(player->getName());
	this->initGeneration();

	do {
		// DATA MANAGEMENT
		int input = view->getKeyboardInput();
		switch (input) {
			case 'q':
				quit = true;
				break;
			case 'e':
				player->shoots(time);
				break;
		}

		player->move(input, view->getGameWidth(), view->getGameHeight(), 
					Platform::checkPlatformAbove(generator->getPlatforms(), generator->getNumberPlatforms(), player->getX(), player->getY()), 
					Platform::checkPlatformBelow(generator->getPlatforms(), generator->getNumberPlatforms(), player->getX(), player->getY()),
					time);
		h->follow(player->getX(), player->getY(), time,
					Platform::checkPlatformAbove(generator->getPlatforms(), generator->getNumberPlatforms(), h->getX(), h->getY()), 
					Platform::checkPlatformBelow(generator->getPlatforms(), generator->getNumberPlatforms(), h->getX(), h->getY()),
					view->getGameWidth(), view->getGameHeight());
		h->shoots(time);
		
		// DRAW MAP
		view->clearWindow();
		view->drawBorders();
		view->printInfos(player->getName(), time, player->getLife(), player->getPoints(), room);

		// PRINT ENTITIES
		view->printObject(player->noOffsetX(), player->getY(), (char *)"%s", player->getSymbol(), 0, player->hasInvincibility());
		this->printShoots(player, 0);
		view->printObject(h->getX(), h->getY(), (char *)"%s", (char *) h->getSymbol(), player->getOffset());
		this->printShoots(h, player->getOffset());
		
		for (int i = 0; i < generator->getNumberPlatforms(); i++) {
			Platform *platf = generator->getPlatform(i);
			view->printPlatform(platf->getX(), platf->getY(), platf->getLenght(), player->getOffset());
		}
		for (int i = 0; i < generator->getNumberBonuses(); i++) {
			Bonus *bonus = generator->getBonus(i);
			view->printObject(bonus->getX(), bonus->getY(), "%s", bonus->getSymbol(), player->getOffset());
		}

		// CHECKING
		player->checkBonusesDuration(time);
		this->checkCollisions();
		this->checkRoomsGeneration();

		view->update();
		time += (double)view->getDelay() / 1000;
	} while (!quit);
	view->exitWindow();
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
	// player - HardEnemy
	if(!player->hasInvincibility() && (player->getX() == h->getX() && player->getY() == h->getY())) {
		player->decreaseLife(h->getAttack());
	}
	// player - Bonuses
	for (int i = 0; i < generator->getNumberBonuses(); i++) {
		Bonus *bonus = generator->getBonus(i);
		if (player->getX() == bonus->getX() && player->getY() == bonus->getY())
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
		case MINIGUN:
			player->setCooldownShoot(bonus->getMinigunCooldown(), time);
			break;
		case RALLENTY:
			// TODO: cambiare cooldown_movement di TUTI i nemici
			break;
	}
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

void Controller::initGeneration() {
	generator->createRoom(room, LEFT_ROOM, view->getGameWidth());
	generator->createRoom(room+1, RIGHT_ROOM, view->getGameWidth());
	generator->createBonuses();
}