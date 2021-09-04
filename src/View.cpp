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
	this->clearWindow();
	box(stdscr, 0, 0);
	this->printGameName();
	this->update();
	WINDOW *win = subwin(stdscr, 1, 17 + MAX_NAME_LENGHT, 12, 2);
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

void View::printInfos(char *username, int room, double time, int life, int points, int level, double invincibility_timer, double minigun_timer) {
	// y_offset is passed by reference
	int y_offset = -1;
	this->printGameInfos(level, room, time, y_offset);
	this->printPlayerInfos(username, life, points, invincibility_timer, minigun_timer, y_offset);
	y_offset = 6;
	this->printLegenda(y_offset);
	this->printCommands(y_offset);
}

void View::printWithAttr(char *label, unsigned int attr, WINDOW *win) {
	wattron(win, attr);
	wprintw(win, label);
	wattroff(win, attr);
}

void View::printPlatform(int x, int y, int length, int offset) {
	for(int i = 0; i < length; i++) {
		printObject(x+i, y, "%s", (char *)"=", offset);
	}
}

void View::printObject(int x, int y, const char* format, char *label, int offset, bool hasInvincibility, bool isDamaged) {
	if (x-offset >= 0 && x-offset < GAME_WIDTH-1) {
		wmove(gamewin, y+1, x+1-offset);
		unsigned int attrs = 0;
		if (isDamaged)
			attrs = A_BLINK;
		if (hasInvincibility)
			attrs = attrs | COLOR_PAIR(INVINCIBILITY_COLOR);
		this->printWithAttr(label, attrs, gamewin);
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

void View::printGameName() {
	int y_offset = 0;
	mvprintw(START_Y_GAME + y_offset++, 2, R"(/$$$$$$$  /$$             /$$      /$$$$$$                                         /$$$$$$                                           /$$$$$$   /$$$$$$   /$$$$$$    /$$  )");
	mvprintw(START_Y_GAME + y_offset++, 2, R"(| $$__  $$| $$            | $$     /$$__  $$                                       /$$__  $$                                         /$$__  $$ /$$$_  $$ /$$__  $$ /$$$$  )");
	mvprintw(START_Y_GAME + y_offset++, 2, R"(| $$  \ $$| $$  /$$$$$$  /$$$$$$  | $$  \__//$$$$$$   /$$$$$$  /$$$$$$/$$$$       | $$  \__/  /$$$$$$  /$$$$$$/$$$$   /$$$$$$       |__/  \ $$| $$$$\ $$|__/  \ $$|_  $$  )");
	mvprintw(START_Y_GAME + y_offset++, 2, R"(| $$$$$$$/| $$ |____  $$|_  $$_/  | $$$$   /$$__  $$ /$$__  $$| $$_  $$_  $$      | $$ /$$$$ |____  $$| $$_  $$_  $$ /$$__  $$        /$$$$$$/| $$ $$ $$  /$$$$$$/  | $$  )");
	mvprintw(START_Y_GAME + y_offset++, 2, R"(| $$____/ | $$  /$$$$$$$  | $$    | $$_/  | $$  \ $$| $$  \__/| $$ \ $$ \ $$      | $$|_  $$  /$$$$$$$| $$ \ $$ \ $$| $$$$$$$$       /$$____/ | $$\ $$$$ /$$____/   | $$  )");
	mvprintw(START_Y_GAME + y_offset++, 2, R"(| $$      | $$ /$$__  $$  | $$ /$$| $$    | $$  | $$| $$      | $$ | $$ | $$      | $$  \ $$ /$$__  $$| $$ | $$ | $$| $$_____/      | $$      | $$ \ $$$| $$        | $$  )");
	mvprintw(START_Y_GAME + y_offset++, 2, R"(| $$      | $$|  $$$$$$$  |  $$$$/| $$    |  $$$$$$/| $$      | $$ | $$ | $$      |  $$$$$$/|  $$$$$$$| $$ | $$ | $$|  $$$$$$$      | $$$$$$$$|  $$$$$$/| $$$$$$$$ /$$$$$$)");
	mvprintw(START_Y_GAME + y_offset++, 2, R"(|__/      |__/ \_______/   \___/  |__/     \______/ |__/      |__/ |__/ |__/       \______/  \_______/|__/ |__/ |__/ \_______/      |________/ \______/ |________/|______/)");
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

void View::printGameOver(int points, double time) {
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
	y_offset += 1;
	mvprintw(START_Y_GAME + y_offset++, x_offset+10, "Hai totalizzato %d points in %.2fs", points, time);
	timeout(4000);
	getch();
}

/*
void View::printErrorDimensions() {
	move(0, 0);
	this->printWithAttr((char *)"ERROR DIMENSIONS:\nCOLOR_PAIR(",) ERROR_MESSAGE);
	printw("\tMINIMUN HEIGHT: %d, MINIMUM WIDTH: %d\n\n", GAME_HEIGHT * 2, GAME_WIDTH * 3);
	printw("\tCurrent height: %d, Current width: %d", height, width);
	update();
}
*/

void View::printGameInfos(int level, int room, double time, int &y_offset) {
	move(START_Y_GAME + y_offset++, START_X_GAME + 1);
	this->printWithAttr((char *)"LEVEL: ", COLOR_PAIR(GAME_INFO_COLOR));
	printw("%d\t\t", 1);
	this->printWithAttr((char *)"ROOM: ", COLOR_PAIR(GAME_INFO_COLOR));
	printw("%d\t\t", room);
	this->printWithAttr((char *)"TIME: ", COLOR_PAIR(GAME_INFO_COLOR));
	printw("%.2fs", time);
}

void View::printPlayerInfos(char *username, int life, int points, double invincibility_timer, double minigun_timer, int &y_offset) {
	move(START_Y_GAME + y_offset++, START_X_GAME + GAME_WIDTH + 8);
	this->printWithAttr((char *)"PLAYER: ", COLOR_PAIR(PLAYER_INFO_COLOR));
	printw("\t%s", username);
	move(START_Y_GAME + y_offset++, START_X_GAME + GAME_WIDTH + 8);
	this->printWithAttr((char *)"LIFE: ", COLOR_PAIR(PLAYER_INFO_COLOR));
	printw("\t%d", life);
	move(START_Y_GAME + y_offset++, START_X_GAME + GAME_WIDTH + 8);
	this->printWithAttr((char *)"POINTS: ", COLOR_PAIR(PLAYER_INFO_COLOR));
	printw("\t%d", points);
	if (invincibility_timer > 0.0) {
		move(START_Y_GAME + y_offset++, START_X_GAME + GAME_WIDTH + 8);
		this->printWithAttr((char *)"I: ", COLOR_PAIR(PLAYER_INFO_COLOR));
		printw("%.2fs", invincibility_timer);
	}
	if (minigun_timer > 0.0) {
		move(START_Y_GAME + y_offset++, START_X_GAME + GAME_WIDTH + 8);
		this->printWithAttr((char *)"G: ", COLOR_PAIR(PLAYER_INFO_COLOR));
		printw("%.2fs", minigun_timer);
	}
}

void View::printLegenda(int &y_offset) {
	move(START_Y_GAME + y_offset++, START_X_GAME + GAME_WIDTH + 8);
	this->printWithAttr((char *)"Legenda:", A_UNDERLINE);
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
	move(START_Y_GAME + GAME_HEIGHT + 3, START_X_GAME + 1);
	this->printWithAttr((char *)"Commands:", A_UNDERLINE);
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