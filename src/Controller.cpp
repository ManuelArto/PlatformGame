#include "Controller.hpp"

Controller::Controller() {
	view = new View();
	player = new Player(0, 0);
	player2 = new Player(10, 10);
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
		case 101:
			player->shoots();
			break;
		}
		player->move(input, view->getWidth(), view->getHeight());
		player2->move(0405, view->getWidth(), view->getHeight());

		view->clearWindow();

		view->printObject(player->getX(), player->getY(), (char *)"S");
		view->printObject(player2->getX(), player2->getY(), (char *)"S");
		for (int i = 0; i < player->getNShots(); i++) {
			p_shot shot = player->getShot(i);
			view->printObject(shot->x, shot->y, (char *)"---");
			player->updateShot(shot, view->getWidth());
		}

		view->update();
	} while (!quit);
	
	view->exitWindow();
}