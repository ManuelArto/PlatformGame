#include "Controller.hpp"

Controller::Controller(View *view, Generator *generator) {
	this->view = view;
	this->generator = generator;
	player = new Player (0, view->getGameHeight()-1);
	h = new HardEnemy(view->getGameWidth()-1, view->getGameHeight()-1);
	m = new MediumEnemy(10, view->getGameHeight()-5);
	e = new EasyEnemy(view->getGameWidth()-3, player->getY());
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
					Platform::checkPlatformBelow(generator->getPlatforms(), generator->getNumberPlatform(), player->getX(), player->getY()),
					time
					);

		h->follow(player->getX(), player->getY(), time,
					Platform::checkPlatformAbove(generator->getPlatforms(), generator->getNumberPlatform(), h->getX(), h->getY()), 
					Platform::checkPlatformBelow(generator->getPlatforms(), generator->getNumberPlatform(), h->getX(), h->getY()),
					view->getGameWidth(), view->getGameHeight());
		h->shoots(time);

		m->shoots(time);

		//da sistemare
		m->movement(player->getX(), player->getY(), time,
					Platform::checkPlatformAbove(generator->getPlatforms(), generator->getNumberPlatform(), m->getX(), m->getY()), 
					Platform::checkPlatformBelow(generator->getPlatforms(), generator->getNumberPlatform(), m->getX(), m->getY()),
					view->getGameWidth(), view->getGameHeight(),
					Platform::checkPlatformBelow(generator->getPlatforms(), generator->getNumberPlatform(), m->getX()+1, m->getY()),
					Platform::checkPlatformBelow(generator->getPlatforms(), generator->getNumberPlatform(), m->getX()-1, m->getY()));
		
		// da rivedere
		if(e != NULL){
			e -> rocket(time, view->getGameWidth(), view->getGameHeight(), player->getY());
		}
		
		// CHECK COLLISION
		this->checkCollisions(e);
		this->checkCollisions(m);
		this->checkCollisions(h);

		// DRAW MAP
		view->clearWindow();
		view->drawBorders();
		view->printInfos(player->getName(), time, player->getLife(), player->getPoints());

		// PRINT ENTITIES
		view->printObject(player->getX(), player->getY(), (char *)"%s", player->getSymbol());
		this->printShoots(player);
		view->printObject(h->getX(), h->getY(), (char *)"%s", (char *) h->getSymbol());
		this->printShoots(h);
		view->printObject(m->getX(), m->getY(), (char *)"%s", (char *) m->getSymbol());
		this->printShoots(m);
		view->printObject(e->getX(), e->getY(), (char *)"%s", (char *) e->getSymbol());
		
		// CREATE AND PRINT PLATFORM
		for (int i = 0; i < generator->getNumberPlatform(); i++) {
			Platform *platf = generator->getPlatform(i);
			view->printPlatform(platf->getX(), platf->getY(), platf->getLenght());
		}

		view->update();
		time += (double)view->getDelay() / 1000;
	} while (!quit);
	view->exitWindow();
}

// da rivedere per easyenemy e per far sparire i colpi
void Controller::checkCollisions(Character *c){
	bool hit = false;
	// PHYSICAL COLLISION
	if((player->getX() == c->getX()) && (player->getY() == c->getY())){
		player->decreaseLife(c->getAttack());
		
		//collisione con il muro
		/*if(c == e && e->getX() == 0){
			e = NULL;
			delete(e);
		}*/
	}

	// SHOOT COLLISION
	p_shot tmp_shot, shot;
	shot = c->getShotHead();
	while(shot != __null && !hit){
		if((player->getX() == shot->x) && (player->getY() == shot->y)){
			player->decreaseLife(c->getAttack());
			//c -> deleteShot(shot);
			hit = true;
		}
		tmp_shot = shot->next;
		c->updateShot(shot, view->getGameWidth());
		shot = tmp_shot;
	}
}

void Controller::printShoots(Character *c){
	p_shot tmp_shot, shot;
	shot = c->getShotHead();
	while(shot != __null){
		view->printObject(shot->x, shot->y, (char *)"%s", (char *)"---");
		tmp_shot = shot->next;
		c->updateShot(shot, view->getGameWidth());
		shot = tmp_shot;
	}
}