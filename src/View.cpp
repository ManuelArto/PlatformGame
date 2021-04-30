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

	gamewin = newwin(GAME_HEIGHT+2, GAME_WIDTH+2, START_Y_GAME, START_X_GAME);
}

void View::drawBorders() {
	box(gamewin, 0, 0);
	box(stdscr, 0, 0);
}

void View::printInfos(char* user, double time, int life, int points, int level, double invincibility_timer, double minigun_timer) {
	int y_offset = -1;
	// Game Infos
	move(START_Y_GAME + y_offset++, START_X_GAME + 1);
	printw("LEVEL: %d\t\t", level);
	printw("TIME: %.2fs", time);
	// Player Infos
	move(START_Y_GAME + y_offset++, START_X_GAME + GAME_WIDTH + 8);
	printw("PLAYER: \t%s", user);
	move(START_Y_GAME + y_offset++, START_X_GAME + GAME_WIDTH + 8);
	printw("LIFE: \t%d", life);
	move(START_Y_GAME + y_offset++, START_X_GAME + GAME_WIDTH + 8);
	printw("POINTS: \t%d", points);
	if (invincibility_timer > 0.0) {
		move(START_Y_GAME + y_offset++, START_X_GAME + GAME_WIDTH + 8);
		printw("I: %.2fs", invincibility_timer);
	}
	if (minigun_timer > 0.0) {
		move(START_Y_GAME + y_offset++, START_X_GAME + GAME_WIDTH + 8);
		printw("G: %.2fs", minigun_timer);
	}
	y_offset = 6;
	// Legenda
	attron(A_UNDERLINE);
	move(START_Y_GAME + y_offset++, START_X_GAME + GAME_WIDTH + 8);
	printw("Legenda:");
	standend();
	printw("\t\t\tG = Minigun");
	move(START_Y_GAME + y_offset++, START_X_GAME + GAME_WIDTH + 8);
	printw("<-- = EasyEnemy\t\t");
	printw("I = Invincibility");
	move(START_Y_GAME + y_offset++, START_X_GAME + GAME_WIDTH + 8);
	printw("M = MediumEnemy\t\t");
	printw("L = Life");
	move(START_Y_GAME + y_offset++, START_X_GAME + GAME_WIDTH + 8);
	printw("H = HardEnemy\t\t");
	printw("P = Points");

	// Commands
	attron(A_UNDERLINE);
	move(START_Y_GAME + GAME_HEIGHT + 3, START_X_GAME + 1);
	printw("Commands:"); 
	standend();
	move(START_Y_GAME + GAME_HEIGHT + 4, START_X_GAME + 1);
	printw("e = shoot || Arrows = move || q = quit"); 
}

void View::printPlatform(int x, int y, int length, int offset) {
	for(int i = 0; i < length; i++) {
		printObject(x+i, y, "%s", (char *)"=", offset);
	}
}

void View::printObject(int x, int y, const char* format, char *object, int offset, bool hasInvincibility) {
	if (x-offset >= 0 && x-offset < GAME_WIDTH-1) {
		if (hasInvincibility) {
			wattron(gamewin, A_UNDERLINE);	// TODO: change color
		}
		wmove(gamewin, y+1, x+1-offset);
		wprintw(gamewin, format, object);
		wstandend(gamewin);
	}
}

void View::printObject(int x, int y, const char* format, int object, int offset) {
	if (x-offset >= 0 && x-offset < GAME_WIDTH-1) {
		wmove(gamewin, y+1, x+1-offset);
		wprintw(gamewin, format, object);
	}
}

void View::printObject(int x, int y, const char* format, double object, int offset) {
	if (x-offset >= 0 && x-offset < GAME_WIDTH-1) {
		wmove(gamewin, y+1, x+1-offset);
		wprintw(gamewin, format, object);
	}
}

void View::update() {
	wnoutrefresh(stdscr);
	wnoutrefresh(gamewin);
	doupdate();
}

void View::printGameOver() {
	move(START_Y_GAME, START_X_GAME);
	printw("\
                   *              )               (     \n \
 (        (      (  `          ( /(               )\\ )  \n \
 )\\ )     )\\     )\\))(   (     )\\()) (   (   (   (()/(  \n \
(()/(  ((((_)(  ((_)()\\  )\\   ((_)\\  )\\  )\\  )\\   /(_)) \n \
 /(_))_ )\\ _ )\\ (_()((_)((_)    ((_)((_)((_)((_) (_))   \n \
(_)) __|(_)_\\(_)|  \\/  || __|  / _ \\\\ \\ / / | __|| _ \\  \n \
  | (_ | / _ \\  | |\\/| || _|  | (_) |\\ V /  | _| |   /  \n \
   \\___|/_/ \\_\\ |_|  |_||___|  \\___/  \\_/   |___||_|_\\  \n ");
	timeout(4000);
	getch();
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