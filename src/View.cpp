#include "View.hpp"

void View::createWindow() {
	initscr();
	scrollok(stdscr, false);
	cbreak();
	curs_set(FALSE);
	keypad(stdscr, TRUE);
	getmaxyx(stdscr, height, width);

	start_color();
	init_pair(INVINCIBILITY_COLOR, COLOR_YELLOW, COLOR_BLACK);
	init_pair(GAME_INFO_COLOR, COLOR_RED, COLOR_BLACK);
	init_pair(PLAYER_INFO_COLOR, COLOR_BLUE, COLOR_BLACK);
	init_pair(ERROR_MESSAGE, COLOR_RED, COLOR_BLACK);

	gamewin = subwin(stdscr, GAME_HEIGHT+2, GAME_WIDTH+2, START_Y_GAME, START_X_GAME);
}

/*
void View::checkDimensions() {
	while(height < GAME_HEIGHT * 2 || width < GAME_WIDTH * 3) {
		this->printErrorDimensions();
		getmaxyx(stdscr, height, width);
		wresize(gamewin, GAME_HEIGHT, GAME_WIDTH);
		touchwin(stdscr);
		touchwin(gamewin);
	}
}
*/

void View::askName(char *name, const int MAX_NAME_LENGHT) {
	box(stdscr, 0, 0);
	this->update();
	WINDOW *win = subwin(stdscr, 1, 17 + MAX_NAME_LENGHT, 2, 2);
	mvwprintw(win, 0, 0, "Inserisci nome: ");
	do {
		wgetstr(win, name);
	} while (!strcmp(name, ""));
	
	timeout(DELAY);
	noecho();
}

void View::drawBorders() {
	box(stdscr, 0, 0);
	box(gamewin, 0, 0);
}

void View::printInfos(char *username, double time, int life, int points, int level, double invincibility_timer, double minigun_timer) {
	int y_offset = -1;
	this->printGameInfos(level, time, y_offset);
	this->printPlayerInfos(username, life, points, invincibility_timer, minigun_timer, y_offset);
	y_offset = 6;
	this->printLegenda(y_offset);
	this->printCommands(y_offset);
}

void View::printWithColor(char *label, int color_pair, WINDOW *win) {
	wattron(win, COLOR_PAIR(color_pair));
	wprintw(win, label);
	wattroff(win, COLOR_PAIR(color_pair));
}

void View::printPlatform(int x, int y, int length, int offset) {
	for(int i = 0; i < length; i++) {
		printObject(x+i, y, "%s", (char *)"=", offset);
	}
}

void View::printObject(int x, int y, const char* format, char *label, int offset, bool hasInvincibility) {
	if (x-offset >= 0 && x-offset < GAME_WIDTH-1) {
		wmove(gamewin, y+1, x+1-offset);
		if (hasInvincibility) {
			this->printWithColor(label, INVINCIBILITY_COLOR, gamewin);
		} else {
			wprintw(gamewin, format, label);
		}
	}
}

void View::printObject(int x, int y, const char* format, int label, int offset) {
	if (x-offset >= 0 && x-offset < GAME_WIDTH-1) {
		wmove(gamewin, y+1, x+1-offset);
		wprintw(gamewin, format, label);
	}
}

void View::printObject(int x, int y, const char* format, double label, int offset) {
	if (x-offset >= 0 && x-offset < GAME_WIDTH-1) {
		wmove(gamewin, y+1, x+1-offset);
		wprintw(gamewin, format, label);
	}
}

void View::update() {
	wnoutrefresh(stdscr);
	doupdate();
}

void View::clearWindow() {
	erase();
	// clear();
}

void View::exitWindow() {
	endwin();
}

void View::printLoadingGame() {
	this->clearWindow();
	box(stdscr, 0, 0);
	int y_offset = 0, x_offset = (width / 2) - 33;
	mvprintw(START_Y_GAME + y_offset++, x_offset, R"(  (       )       (    (       )                          *         )");
	mvprintw(START_Y_GAME + y_offset++, x_offset, R"(  )\ ) ( /(  (    )\ ) )\ ) ( /( (        (       (     (  `        )");
	mvprintw(START_Y_GAME + y_offset++, x_offset, R"( (()/( )\()) )\  (()/((()/( )\()))\ )     )\ )    )\    )\))(  (    )");
	mvprintw(START_Y_GAME + y_offset++, x_offset, R"(  /(_)|(_)((((_)( /(_))/(_)|(_)\(()/(    (()/( ((((_)( ((_)()\ )\   )");
	mvprintw(START_Y_GAME + y_offset++, x_offset, R"( (_))   ((_)\ _ )(_))_(_))  _((_)/(_))_   /(_))_)\ _ )\(_()((_|(_)  )");
	mvprintw(START_Y_GAME + y_offset++, x_offset, R"( | |   / _ (_)_\(_)   \_ _|| \| (_)) __| (_)) __(_)_\(_)  \/  | __| )");
	mvprintw(START_Y_GAME + y_offset++, x_offset, R"( | |__| (_) / _ \ | |) | | | .` | | (_ |   | (_ |/ _ \ | |\/| | _|  )");
	mvprintw(START_Y_GAME + y_offset++, x_offset, R"( |____|\___/_/ \_\|___/___||_|\_|  \___|    \___/_/ \_\|_|  |_|___| )");
	
	timeout(4000);
	getch();
	this->clearWindow();
	update();
}

void View::printGameOver() {
	this->clearWindow();
	box(stdscr, 0, 0);
	int y_offset = 0, x_offset = (width / 2) - 25;
	mvprintw(START_Y_GAME + y_offset++, x_offset, R"(                  *             )            (     )");
	mvprintw(START_Y_GAME + y_offset++, x_offset, R"(  (       (     (  `         ( /(            )\ )  )");
	mvprintw(START_Y_GAME + y_offset++, x_offset, R"(  )\ )    )\    )\))(  (     )\())(   (  (  (()/(  )");
	mvprintw(START_Y_GAME + y_offset++, x_offset, R"( (()/( ((((_)( ((_)()\ )\   ((_)\ )\  )\ )\  /(_)) )");
	mvprintw(START_Y_GAME + y_offset++, x_offset, R"(  /(_))_)\ _ )\(_()((_|(_)    ((_|(_)((_|(_)(_))   )");
	mvprintw(START_Y_GAME + y_offset++, x_offset, R"( (_)) __(_)_\(_)  \/  | __|  / _ \ \ / /| __| _ \  )");
	mvprintw(START_Y_GAME + y_offset++, x_offset, R"(   | (_ |/ _ \ | |\/| | _|  | (_) \ V / | _||   /  )");
	mvprintw(START_Y_GAME + y_offset++, x_offset, R"(    \___/_/ \_\|_|  |_|___|  \___/ \_/  |___|_|_\  )");
	timeout(4000);
	getch();
}

/*
void View::printErrorDimensions() {
	move(0, 0);
	this->printWithColor((char *)"ERROR DIMENSIONS:\n", ERROR_MESSAGE);
	printw("\tMINIMUN HEIGHT: %d, MINIMUM WIDTH: %d\n\n", GAME_HEIGHT * 2, GAME_WIDTH * 3);
	printw("\tCurrent height: %d, Current width: %d", height, width);
	update();
}
*/

void View::printGameInfos(int level, double time, int &y_offset) {
	move(START_Y_GAME + y_offset++, START_X_GAME + 1);
	this->printWithColor((char *)"LEVEL: ", GAME_INFO_COLOR);
	printw("%d, %d\t\t", height, width);
	this->printWithColor((char *)"TIME: ", GAME_INFO_COLOR);
	printw("%.2fs", time);
}

void View::printPlayerInfos(char *username, int life, int points, double invincibility_timer, double minigun_timer, int &y_offset) {
	move(START_Y_GAME + y_offset++, START_X_GAME + GAME_WIDTH + 8);
	this->printWithColor((char *)"PLAYER: ", PLAYER_INFO_COLOR);
	printw("\t%s", username);
	move(START_Y_GAME + y_offset++, START_X_GAME + GAME_WIDTH + 8);
	this->printWithColor((char *)"LIFE: ", PLAYER_INFO_COLOR);
	printw("\t%d", life);
	move(START_Y_GAME + y_offset++, START_X_GAME + GAME_WIDTH + 8);
	this->printWithColor((char *)"POINTS: ", PLAYER_INFO_COLOR);
	printw("\t%d", points);
	if (invincibility_timer > 0.0) {
		move(START_Y_GAME + y_offset++, START_X_GAME + GAME_WIDTH + 8);
		this->printWithColor((char *)"I: ", PLAYER_INFO_COLOR);
		printw("%.2fs", invincibility_timer);
	}
	if (minigun_timer > 0.0) {
		move(START_Y_GAME + y_offset++, START_X_GAME + GAME_WIDTH + 8);
		this->printWithColor((char *)"G: ", PLAYER_INFO_COLOR);
		printw("%.2fs", minigun_timer);
	}
}

void View::printLegenda(int &y_offset) {
	attron(A_UNDERLINE);
	move(START_Y_GAME + y_offset++, START_X_GAME + GAME_WIDTH + 8);
	printw("Legenda:");
	attroff(A_UNDERLINE);
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
}

void View::printCommands(int &y_offset) {
	attron(A_UNDERLINE);
	move(START_Y_GAME + GAME_HEIGHT + 3, START_X_GAME + 1);
	printw("Commands:"); 
	attroff(A_UNDERLINE);
	move(START_Y_GAME + GAME_HEIGHT + 4, START_X_GAME + 1);
	printw("e = shoot || Arrows = move || q = quit"); 
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