#include "Controller.hpp"
#include <iostream>
Controller::Controller(View *view) {
	this->view = view;
	player = new Player(1, 18);
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
			//p = platform -> create_platform((rand()%44)+1, (rand()%8)+10, 5, p);
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
		/*view->printObject(16,14, (char *)"%s", (char *) m->symbol());
		view->printObject(18,14, (char *)"%s", (char *) h->symbol());*/
		//e -> shoots(time);

		if(input == 0403){
			if((platform->checkPlatformUp(player -> getX(), player -> getY(), p))){
				player -> move(input, 49, 19);
			}
		}else if(input == 0402){
			if((platform->checkPlatformDown(player -> getX(), player -> getY(), p))){}
		}else{
			player->move(input, 49, 19);
		}
		//se la piattaforma finisce ti riporta giu
		if((platform -> checkPlatformDown(player -> getX(), player -> getY(), p) == false)){
			player->move(0402, 49, 19);
		}

		p_shot tmp_shot, shot = player->getShotHead();
		while (shot != __null) {
			view->printObject(shot->x, shot->y, (char *)"%s", (char *)"---");
			tmp_shot = shot->next;
			player->updateShot(shot, 49);
			shot = tmp_shot;
		}

		/*p_shot tmp_shot2, shot2 = e->getShotHeadEnemy();
		while (shot2 != __null) {
			view->printObject(shot2->x, shot2->y, (char *)"%s", (char *)"<--");
			tmp_shot2 = shot2->next;
			e ->updateShotEnemy(shot2);
			shot2 = tmp_shot2;
		}*/

		view->update();
		time += (double)view->getDelay() / 1000;
	} while (!quit);
	
	view->exitWindow();
}