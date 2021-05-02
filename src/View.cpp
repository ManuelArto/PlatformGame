#include "View.hpp"

#define INVINCIBILITY_COLOR 1
#define GAME_INFO_COLOR 2
#define PLAYER_INFO_COLOR 3

void View::createWindow() {
    setlocale(LC_CTYPE, "");
	
	initscr();
	cbreak();
	curs_set(FALSE);
	keypad(stdscr, TRUE);
	getmaxyx(stdscr, height, width);
	
	start_color();
	init_pair(INVINCIBILITY_COLOR, COLOR_YELLOW, COLOR_BLACK);
	init_pair(GAME_INFO_COLOR, COLOR_RED, COLOR_BLACK);
	init_pair(PLAYER_INFO_COLOR, COLOR_BLUE, COLOR_BLACK);

	gamewin = newwin(GAME_HEIGHT+2, GAME_WIDTH+2, START_Y_GAME, START_X_GAME);
}

void View::askName(char *name) {
	box(stdscr, 0, 0);
	update();
	WINDOW *win = newwin(1, 27, 2, 2);
	do {
		mvwprintw(win, 0, 0, "Inserisci nome: ");
		wrefresh(win);
		wgetstr(win, name);
	} while (!strcmp(name, ""));
	delwin(win);
	
	timeout(DELAY);
	noecho();
}

void View::drawBorders() {
	box(stdscr, 0, 0);
	box(gamewin, 0, 0);
}

// TODO: redefined printObject to accept Color management
void View::printInfos(char* username, double time, int life, int points, int level, double invincibility_timer, double minigun_timer) {
	int y_offset = -1;
	// Game Infos
	attron(COLOR_PAIR(GAME_INFO_COLOR));
	move(START_Y_GAME + y_offset++, START_X_GAME + 1);
	printw("LEVEL: ");
	standend();
	printw("%d\t\t", level);
	attron(COLOR_PAIR(GAME_INFO_COLOR));
	printw("TIME: ");
	standend();
	printw("%.2fs", time);
	// Player Infos
	move(START_Y_GAME + y_offset++, START_X_GAME + GAME_WIDTH + 8);
	attron(COLOR_PAIR(PLAYER_INFO_COLOR));
	printw("PLAYER: ");
	standend();
	printw("\t%s", username);
	move(START_Y_GAME + y_offset++, START_X_GAME + GAME_WIDTH + 8);
	attron(COLOR_PAIR(PLAYER_INFO_COLOR));
	printw("LIFE: ");
	standend();
	printw("\t%d", life);
	move(START_Y_GAME + y_offset++, START_X_GAME + GAME_WIDTH + 8);
	attron(COLOR_PAIR(PLAYER_INFO_COLOR));
	printw("POINTS: ");
	standend();
	printw("\t%d", points);
	if (invincibility_timer > 0.0) {
		move(START_Y_GAME + y_offset++, START_X_GAME + GAME_WIDTH + 8);
		attron(COLOR_PAIR(PLAYER_INFO_COLOR));
		printw("I: ");
		standend();
		printw("%.2fs", invincibility_timer);
	}
	if (minigun_timer > 0.0) {
		move(START_Y_GAME + y_offset++, START_X_GAME + GAME_WIDTH + 8);
		attron(COLOR_PAIR(PLAYER_INFO_COLOR));
		printw("G: ");
		standend();
		printw("%.2fs", minigun_timer);
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
			wattron(gamewin, COLOR_PAIR(INVINCIBILITY_COLOR));
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

void View::printLoadingGame() {
	box(stdscr, 0, 0);
	int y_offset = 0, x_offset = (width / 2) - 32;
	mvprintw(START_Y_GAME + y_offset++, x_offset, " (       )       (    (       )                          *         ");
	mvprintw(START_Y_GAME + y_offset++, x_offset, " )\\ ) ( /(  (    )\\ ) )\\ ) ( /( (        (       (     (  `        ");
	mvprintw(START_Y_GAME + y_offset++, x_offset, "(()/( )\\()) )\\  (()/((()/( )\\()))\\ )     )\\ )    )\\    )\\))(  (    ");
	mvprintw(START_Y_GAME + y_offset++, x_offset, " /(_)|(_)((((_)( /(_))/(_)|(_)\\(()/(    (()/( ((((_)( ((_)()\\ )\\   ");
	mvprintw(START_Y_GAME + y_offset++, x_offset, "(_))   ((_)\\ _ )(_))_(_))  _((_)/(_))_   /(_))_)\\ _ )\\(_()((_|(_)  ");
	mvprintw(START_Y_GAME + y_offset++, x_offset, "| |   / _ (_)_\\(_)   \\_ _|| \\| (_)) __| (_)) __(_)_\\(_)  \\/  | __| ");
	mvprintw(START_Y_GAME + y_offset++, x_offset, "| |__| (_) / _ \\ | |) | | | .` | | (_ |   | (_ |/ _ \\ | |\\/| | _|  ");
	mvprintw(START_Y_GAME + y_offset++, x_offset, "|____|\\___/_/ \\_\\|___/___||_|\\_|  \\___|    \\___/_/ \\_\\|_|  |_|___| ");
	timeout(10000);
	getch();
}

void View::printGameOver() {
	box(stdscr, 0, 0);
	int y_offset = 0, x_offset = (width / 2) - 24;
	mvprintw(START_Y_GAME + y_offset++, x_offset, "                 *             )            (     ");
	mvprintw(START_Y_GAME + y_offset++, x_offset, " (       (     (  `         ( /(            )\\ )  ");
	mvprintw(START_Y_GAME + y_offset++, x_offset, " )\\ )    )\\    )\\))(  (     )\\())(   (  (  (()/(  ");
	mvprintw(START_Y_GAME + y_offset++, x_offset, "(()/( ((((_)( ((_)()\\ )\\   ((_)\\ )\\  )\\ )\\  /(_)) ");
	mvprintw(START_Y_GAME + y_offset++, x_offset, " /(_))_)\\ _ )\\(_()((_|(_)    ((_|(_)((_|(_)(_))   ");
	mvprintw(START_Y_GAME + y_offset++, x_offset, "(_)) __(_)_\\(_)  \\/  | __|  / _ \\ \\ / /| __| _ \\  ");
	mvprintw(START_Y_GAME + y_offset++, x_offset, "  | (_ |/ _ \\ | |\\/| | _|  | (_) \\ V / | _||   /  ");
	mvprintw(START_Y_GAME + y_offset++, x_offset, "   \\___/_/ \\_\\|_|  |_|___|  \\___/ \\_/  |___|_|_\\  ");
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