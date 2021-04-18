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

	do {
		// INPUT
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
					Platform::checkPlatformUp(generator->getPlatforms(), generator->getNumberPlatform(), player->getX(), player->getY()), 
					Platform::checkPlatformDown(generator->getPlatforms(), generator->getNumberPlatform(), player->getX(), player->getY())
					);
		h->follow(player->getX(), player->getY(), time, 
					Platform::checkPlatformUp(generator->getPlatforms(), generator->getNumberPlatform(), h->getX(), h->getY()), 
					Platform::checkPlatformDown(generator->getPlatforms(), generator->getNumberPlatform(), h->getX(), h->getY()),
					view->getGameWidth(), view->getGameHeight());

		// DRAW MAP
		view->clearWindow();
		view->drawBorders();
		view->printInfos(player->getName(), time, player->getLife(), player->getPoints());

		// PRINT ENTITIES
		view->printObject(player->getX(), player->getY(), (char *)"%s", player->getSymbol());
		view->printObject(h->getX(), h->getY(), (char *)"%s", (char *) h->getSymbol());
			
		p_shot tmp_shot, shot = player->getShotHead();
		while(shot != __null){
			view->printObject(shot->x, shot->y, (char *)"%s", (char *)"---");
			tmp_shot = shot->next;
			player->updateShot(shot, view->getGameWidth());
			shot = tmp_shot;
		}

		for (int i = 0; i < generator->getNumberPlatform(); i++) {
			Platform *platf = generator->getPlatform(i);
			view->printPlatform(platf->getX(), platf->getY(), platf->getLenght());
		}

		view->update();
		time += (double)view->getDelay() / 1000;
	} while (!quit);
	
	view->exitWindow();
}