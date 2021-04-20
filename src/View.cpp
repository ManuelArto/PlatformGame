#include "View.hpp"

void View::askName(char *name) {
	WINDOW *win = newwin(1, 27, 0, 0);
	mvwprintw(win, 0, 0, "Inserisci nome: ");
	wrefresh(win);
	wgetstr(win, name);
	delwin(win);
	noecho();
}

void View::createWindow() {
    setlocale(LC_CTYPE, "");
	// TODO: check implementation details
	initscr();
	cbreak();
	curs_set(FALSE);
	keypad(stdscr, TRUE);
	timeout(DELAY);
	getmaxyx(stdscr, height, width);
	
	start_color();
	// init_pair(1, COLOR_RED, COLOR_BLACK);
    // attron(A_BOLD);
    // color_set(1, NULL);

	gamewin = newwin(GAME_HEIGHT+2, GAME_WIDTH+2, Y_GAME, X_GAME);
}

void View::drawBorders() {
	box(gamewin, 0, 0);
	box(stdscr, 0, 0);
}

void View::printInfos(char* user, double time, int life, int points) {
	// Infos
	move(Y_GAME, X_GAME + GAME_WIDTH + 8);
	printw("PLAYER: ");
	printw(user);
	move(Y_GAME + 1, X_GAME + GAME_WIDTH + 8);
	printw("TIME: ");
	printw((char *)"%.2f", time);
	move(Y_GAME + 2, X_GAME + GAME_WIDTH + 8);
	printw("LIFE: ");
	printw((char *)"%d", life);
	move(Y_GAME + 3, X_GAME + GAME_WIDTH + 8);
	printw("POINTS: ");
	printw((char *)"%d", points);
	move(Y_GAME + 4, X_GAME + GAME_WIDTH + 8);
	printw("LEVEL: ");
	move(Y_GAME + 5, X_GAME + GAME_WIDTH + 8);
	printw("ROOM: ");
	// Legenda
	attron(A_UNDERLINE);
	move(Y_GAME + 7, X_GAME + GAME_WIDTH + 8);
	printw("Legenda:");
	standend();
	move(Y_GAME + 8, X_GAME + GAME_WIDTH + 8);
	printw("@ = bonus");
	move(Y_GAME + 9, X_GAME + GAME_WIDTH + 8);
	printw("<-- = EasyEnemy");
	move(Y_GAME + 10, X_GAME + GAME_WIDTH + 8);
	printw("M = MediumEnemy");
	move(Y_GAME + 11, X_GAME + GAME_WIDTH + 8);
	printw("H = HardEnemy");
	// Commands
	attron(A_UNDERLINE);
	move(Y_GAME + GAME_HEIGHT + 3, X_GAME + 1);
	printw("Commands:"); 
	standend();
	move(Y_GAME + GAME_HEIGHT + 4, X_GAME + 1);
	printw("e = shoot || Arrows = move || q = quit"); 
}

void View::printPlatform(int x, int y, int length, int offset) {
	for(int i = 0; i < length; i++) {
		printObject(x+i, y, "%s", (char *)"=", offset);
	}
}

void View::printObject(int x, int y, const char* format, char *object, int offset, bool hasInvincibility) {
	if (x-offset >= 0 && x-offset < width-1) {
		if (hasInvincibility) {
			wattron(gamewin, A_UNDERLINE);	// TODO: change color
		}
		wmove(gamewin, y+1, x+1-offset);
		wprintw(gamewin, format, object);
		wstandend(gamewin);
	}
}

void View::printObject(int x, int y, const char* format, int object, int offset) {
	if (x-offset >= 0 && x-offset < width-1) {
		wmove(gamewin, y+1, x+1-offset);
		wprintw(gamewin, format, object);
	}
}

void View::printObject(int x, int y, const char* format, double object, int offset) {
	if (x-offset >= 0 && x-offset < width-1) {
		wmove(gamewin, y+1, x+1-offset);
		wprintw(gamewin, format, object);
	}
}

void View::update() {
	wnoutrefresh(stdscr);
	wnoutrefresh(gamewin);
	doupdate();
}

void View::clearWindow() {
	werase(gamewin);
	erase();
	// wclear(gamewin);
	// clear();
}

void View::exitWindow() {
	endwin();
}

int View::getKeyboardInput() {
	return getch();
}
int View::getDelay() {
	return DELAY;
}
int View::getWidth() {
	return width;
}
int View::getHeight() {
	return height;
}
int View::getGameWidth() {
	return GAME_WIDTH;
}
int View::getGameHeight() {
	return GAME_HEIGHT;
}