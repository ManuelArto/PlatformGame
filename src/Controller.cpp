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
					Platform::checkPlatformAbove(generator->getPlatforms(), generator->getNumberPlatform(), player->getX(), player->getY()), 
					Platform::checkPlatformBelow(generator->getPlatforms(), generator->getNumberPlatform(), player->getX(), player->getY())
					);
		h->follow(player->getX(), player->getY(), time, 
					Platform::checkPlatformAbove(generator->getPlatforms(), generator->getNumberPlatform(), h->getX(), h->getY()), 
					Platform::checkPlatformBelow(generator->getPlatforms(), generator->getNumberPlatform(), h->getX(), h->getY()),
					view->getGameWidth(), view->getGameHeight());
		//h->shoots(time);
		collision();
		// DRAW MAP
		view->clearWindow();
		view->drawBorders();
		view->printInfos(player->getName(), time, player->getLife(), player->getPoints());

		// PRINT ENTITIES
		view->printObject(player->getX(), player->getY(), (char *)"%s", player->getSymbol());
		view->printObject(h->getX(), h->getY(), (char *)"%s", (char *) h->getSymbol());
			
		// PRINT SHOOT PLAYER AND ENEMY
		shoot(player->getShotHead(), player->getShotHead());
		shoot(h->getShotHead(), h->getShotHead());
		
		// PRINT AND GENERATE PLATFORM
		for (int i = 0; i < generator->getNumberPlatform(); i++) {
			Platform *platf = generator->getPlatform(i);
			view->printPlatform(platf->getX(), platf->getY(), platf->getLenght());
		}

		view->update();
		time += (double)view->getDelay() / 1000;
	} while (!quit);
	view->exitWindow();
}

void Controller::collision(){
	if((player->getX() == h->getX()) && (player->getY() == h->getY())){
		player->decreaseLife(h->getAttack());
	}
}

//funziona solo per player, da risolvere
void Controller::shoot(p_shot tmp_shot, p_shot shot){
	while(shot != __null){
			view->printObject(shot->x, shot->y, (char *)"%s", (char *)"---");
			tmp_shot = shot->next;
			player->updateShot(shot, view->getGameWidth());		//risolvere qui
			shot = tmp_shot;
		}
}