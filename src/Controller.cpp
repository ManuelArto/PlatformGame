#include "Controller.hpp"

Controller::Controller() {
	view = new View();
	player = new Player(0, 0);
	player2 = new Player(10, 10);
	time = 0;
}

void Controller::run() {
	view->createWindow();
	bool quit = false;

	do {
		int input = view->getKeyboardInput();
		switch (input) {
			case 113:			// 'q'
				quit = true;
				break;
			case 101:			// 'e'
				player->shoots(time);
				break;
		}
		player->move(input, view->getWidth(), view->getHeight());
		player2->move(0405, view->getWidth(), view->getHeight());

		view->clearWindow();

		view->printObject(0, view->getHeight()-1, (char *)"%.2f", time);
		view->printObject(player->getX(), player->getY(), (char *)"%s", (char *)"S");
		view->printObject(player2->getX(), player2->getY(), (char *)"%s", (char *)"S");
		for (int i = 0; i < player->getNShots(); i++) {
			p_shot shot = player->getShot(i);
			view->printObject(shot->x, shot->y, (char *)"%s", (char *)"---");
			player->updateShot(shot, view->getWidth());
		}

		view->update();
		time += (double)view->getDelay() / 1000;
	} while (!quit);
	
	view->exitWindow();
}