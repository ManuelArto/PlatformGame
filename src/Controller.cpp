#include "Controller.hpp"
Controller::Controller(View *view, Generator *generator) {
	this->view = view;
	this->generator = generator;
	player = new Player (0, view->getGameHeight()-1);
	h = new HardEnemy(view->getGameWidth()-1, view->getGameHeight()-1);
	time = 0;
}

void Controller::run() {
	bool quit = false;
	view->createWindow();
	view->askName(player->getName());
	generator->createPlatforms();
	generator->createBonuses();

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
					Platform::checkPlatformAbove(generator->getPlatforms(), generator->getNumberPlatform(), player->getX(), player->getY()), 
					Platform::checkPlatformBelow(generator->getPlatforms(), generator->getNumberPlatform(), player->getX(), player->getY()),
					time
					);
		h->follow(player->getX(), player->getY(), time,
					Platform::checkPlatformAbove(generator->getPlatforms(), generator->getNumberPlatform(), h->getX(), h->getY()), 
					Platform::checkPlatformBelow(generator->getPlatforms(), generator->getNumberPlatform(), h->getX(), h->getY()),
					view->getGameWidth(), view->getGameHeight());
		h->shoots(time);
		
		// DRAW MAP
		view->clearWindow();
		view->drawBorders();
		view->printInfos(player->getName(), time, player->getLife(), player->getPoints());

		// PRINT ENTITIES
		view->printObject(player->getX(), player->getY(), (char *)"%s", player->getSymbol(), player->hasInvincibility());
		this->printShoots(player);
		view->printObject(h->getX(), h->getY(), (char *)"%s", (char *) h->getSymbol());
		this->printShoots(h);
		
		for (int i = 0; i < generator->getNumberPlatform(); i++) {
			Platform *platf = generator->getPlatform(i);
			view->printPlatform(platf->getX(), platf->getY(), platf->getLenght());
		}
		for (int i = 0; i < generator->getNumberBonus(); i++) {
			Bonus *bonus = generator->getBonus(i);
			view->printObject(bonus->getX(), bonus->getY(), "%s", bonus->getSymbol());
		}

		// CHECKING
		player->checkBonusesDuration(time);
		this->checkCollisions();

		view->update();
		time += (double)view->getDelay() / 1000;
	} while (!quit);
	view->exitWindow();
}

void Controller::checkCollisions() {
	// player - HardEnemy
	if(!player->hasInvincibility() && (player->getX() == h->getX() && player->getY() == h->getY())) {
		player->decreaseLife(h->getAttack());
	}
	// player - Bonuses
	for (int i = 0; i < generator->getNumberBonus(); i++) {
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

void Controller::printShoots(Character *c) {
	p_shot tmp_shot, shot;
	shot = c->getShotHead();
	while(shot != __null){
		view->printObject(shot->x, shot->y, (char *)"%s", (char *)"---");
		tmp_shot = shot->next;
		c->updateShot(shot, view->getGameWidth());
		shot = tmp_shot;
	}
}