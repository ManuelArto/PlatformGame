#include "Controller.hpp"

Controller::Controller(View *view) {
	this->view = view;
	player = new Player(0, 0);
	player2 = new Player(10, 10);
	time = 0;
}

void Controller::run() {
	view->createWindow(	);
	bool quit = false;
	char *name = player->getName();
	
	do {
		view->info_commands(2, 2, 20, 50, name, time);
		view->drawMap(2, 2, 20, 50);
		//view->info_commands(0, 0, view->getHeight(), view->getWidth(), name);
		//view->drawMap(0, 0, view->getHeight(), view->getWidth());
		int input = view->getKeyboardInput();
		switch (input) {
			case 113:			// 'q'
				quit = true;
				break;
			case 101:			// 'e'
				player->shoots(time);
				break;
		}
		
		player->move(input, 48, 18);
		player2->move(0405, 48, 18);
		/*player->move(input, view->getWidth(), view->getHeight());
		player2->move(0405, view->getWidth(), view->getHeight());*/

		view->clearWindow();

		//view->printObject(0, view->getHeight()-1, (char *)"%.2f", time);
		view->printObject(player->getX()+3, player->getY()+3, (char *)"%s", (char *)"S");
		view->printObject(player2->getX()+1, player2->getY(), (char *)"%s", (char *)"F");
		
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