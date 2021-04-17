#include "Controller.hpp"
#include <iostream>
Controller::Controller(View *view) {
	this->view = view;
	player = new Player(1, 18);
	h = new HardEnemy(48, 18);
	time = 0;
}

void Controller::run() {
	view->createWindow(	);
	bool quit = false;
	char* name = player->getName();
	int c=0;
	p_plat p = __null;

	do {
		view->info_commands(0, 0, 20, 50, name, time, player->getLife(), player->getPoints());
		view->drawMap(0, 0, 20, 50);
		if(c<3){		//per creare n piattaforme
			p = platform -> create_platform(1, 17, 5, p);
			p = platform -> create_platform(14, 17, 5, p);
			view->drawPlatform(p);
			c++;
		}

		view->drawPlatform(p);
		int input = view->getKeyboardInput();
		switch (input) {
			case 113:			// 'q'
				quit = true;
				break;
			case 101:			// 'e'
				player->shoots(time);
				break;
		}

		view->clearWindow();

		view->printObject(player->getX(), player->getY(), (char *)"%s", (char *)"S");
		view->printObject(h->getX(), h->getY(), (char *)"%s", (char *) h->symbol());

		if(input == 0403){
			if((platform->checkPlatformUp(player -> getX(), player -> getY(), p))){
				player -> movement(input, 49, 19);
			}
		}else if(input == 0402){
			if((platform->checkPlatformDown(player -> getX(), player -> getY(), p))){}
		}else{
			player->movement(input, 49, 19);
		}
		//se la piattaforma finisce ti riporta giù
		if((platform -> checkPlatformDown(player -> getX(), player -> getY(), p) == false)){
			player->movement(0402, 49, 19);
		}

		h->follower(player->getX(), player->getY());

		p_shot tmp_shot, shot = player->getShotHead();
		while(shot != __null){
			view->printObject(shot->x, shot->y, (char *)"%s", (char *)"---");
			tmp_shot = shot->next;
			player->updateShot(shot, 49);
			shot = tmp_shot;
		}

		view->update();
		time += (double)view->getDelay() / 1000;
	} while (!quit);
	
	view->exitWindow();
}