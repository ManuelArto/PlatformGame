#include "View.hpp"

#include <ncurses.h>

void View::clearWindow() {
	clear();
}

void View::createWindow() {
	// TODO: check implementation details
	initscr();
	noecho();
    cbreak();
    nodelay(stdscr, TRUE);
	curs_set(FALSE);
	keypad(stdscr, TRUE);
	
	getmaxyx(stdscr, height, width);
	timeout(DELAY);
}

void View::drawMap() {

}

void View::exitWindow() {
	endwin();
}

void View::printObject(int x, int y, char *object) {
	mvaddstr(y, x, object);
}

void View::update() {
	refresh();
}

int View::getKeyboardInput() {
	return getch();
}

int View::getWidth() {
	return width;
}

int View::getHeight() {
	return height;
}