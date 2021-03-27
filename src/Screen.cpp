#include "Screen.hpp"

#include <ncurses.h>
#include <unistd.h>

void Screen::clearWindow() {
	clear();
}

void Screen::createWindow() {
	initscr();
	noecho();
	curs_set(FALSE);
	getmaxyx(stdscr, height, width);
}

void Screen::exitWindow() {
	endwin();
}

void Screen::printObject(int x, int y, char *object) {
	mvprintw(y, x, object);
	refresh();
}

void Screen::sleep(int delay) {
	timeout(delay);
}

int Screen::getWidth() {
	return width;
}

int Screen::getHeight() {
	return height;
}