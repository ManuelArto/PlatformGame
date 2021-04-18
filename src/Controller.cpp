#include "Controller.hpp"
Controller::Controller(View *view) {
	this->view = view;
	player = new Player (0, view->getGameHeight()-1);
	time = 0;
}

void Controller::run() {
	view->createWindow();
	view->askName(player->getName());
	bool quit = false;
	// int c = 0;
	// p_plat p = __null;

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

		player->move(input, view->getGameWidth(), view->getGameHeight());
		// if(input == 0403){
		// 	if((platform->checkPlatformUp(player -> getX(), player -> getY(), p))){
		// 		player -> move(input, 49, 19);
		// 	}
		// }else if(input == 0402){
		// 	if((platform->checkPlatformDown(player -> getX(), player -> getY(), p))){}
		// }else{
		// 	player->move(input, 49, 19);
		// }
		// //se la piattaforma finisce ti riporta giu
		// if((platform -> checkPlatformDown(player -> getX(), player -> getY(), p) == false)){
		// 	player->move(0402, 49, 19);
		// }

		// DRAW MAP
		view->clearWindow();
		view->drawBorders();
		view->printInfos(player->getName(), time, player->getLife(), player->getPoints());

		// PRINT ENTITIES
		
		// if(c<3){		//per creare n piattaforme
		// 	//p = platform -> create_platform((rand()%44)+1, (rand()%8)+10, 5, p);
		// 	p = platform -> create_platform(1, 17, 5, p);
		// 	p = platform -> create_platform(14, 17, 5, p);
		// 	view->drawPlatform(p);
		// 	c++;
		// }
		// view->drawPlatform(p);

		view->printObject(player->getX(), player->getY(), (char *)"%s", player->getSymbol());

		p_shot tmp_shot, shot = player->getShotHead();
		while (shot != __null) {
			view->printObject(shot->x, shot->y, (char *)"%s", (char *)"---");
			tmp_shot = shot->next;
			player->updateShot(shot, view->getGameWidth());
			shot = tmp_shot;
		}

		view->update();
		time += (double)view->getDelay() / 1000;
	} while (!quit);
	
	view->exitWindow();
}