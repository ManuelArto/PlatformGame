#include "Controller.hpp"
#include <unistd.h>

Controller::Controller() {
	screen = new Screen();
	player = new Player(0, 0);
}

void Controller::init() {
	screen->clearWindow();
	screen->createWindow();

	int x = 0, y = 0, step = 1;	
	while (1) {
		screen->clearWindow();
		screen->printObject(x, y, (char *)"o");
		

		if (x >= screen->getWidth())
			step = -1;
		else if (x == 0)
			step = 1;

		x += step;

		usleep(6000);
	}
	
	screen->exitWindow();
}