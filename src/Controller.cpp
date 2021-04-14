#include "Controller.hpp"
#include <iostream>

Controller::Controller(View *view) {
	this->view = view;
	player = new Player(3, 20);
	time = 0;
}

void Controller::run() {
	view->createWindow(	);
	bool quit = false;
	char* name = player->getName();
	int c=0;
	p_plat p = __null;

	do {
		view->info_commands(2, 2, 20, 50, name, time, player->getLife(), player->getPoints());
		view->drawMap(2, 2, 20, 50);

		if(c<3){		//per stampare 3 piattaforme
			p = platform -> create_platform(rand()%40, rand()%40, 5, p);
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

		if(input == 0403){

		}

		player->move(input, 48, 18);

		view->clearWindow();

		view->printObject(player->getX(), player->getY(), (char *)"%s", (char *)"S");
		
		p_shot tmp_shot, shot = player->getShotHead();

		while (shot != __null) {
			view->printObject(shot->x+3, shot->y+3, (char *)"%s", (char *)"---");
			tmp_shot = shot->next;
			player->updateShot(shot, view->getWidth());
			shot = tmp_shot;
		}
		view->update();
		time += (double)view->getDelay() / 1000;
	} while (!quit);
	
	view->exitWindow();
}