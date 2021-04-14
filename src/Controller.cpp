#include "Controller.hpp"

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

		if(c<2){		//per creare 3 piattaforme
			//p = platform -> create_platform((rand()%44)+1, (rand()%8)+10, 5, p);
			p = platform -> create_platform(10, 17, 5, p);
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
		if(input == 0403){
			if(platform->checkPlatform(player -> getX(), player -> getY(), p)){
				player -> move(input, 49, 19);
			}
		}else{
			player->move(input, 49, 19);
		}

		p_shot tmp_shot, shot = player->getShotHead();
		while (shot != __null) {
			view->printObject(shot->x, shot->y, (char *)"%s", (char *)"---");
			tmp_shot = shot->next;
			player->updateShot(shot, view->getWidth());
			shot = tmp_shot;
		}
		view->update();
		time += (double)view->getDelay() / 1000;
	} while (!quit);
	
	view->exitWindow();
}