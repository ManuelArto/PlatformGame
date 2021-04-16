#include "View.hpp"
#include <iostream>
using namespace std;

#if defined(_WIN64) || defined(__WIN32)
	#include <curses.h>
#elif __linux
	#include <ncurses.h>
#endif

void View::clearWindow() {
	clear();
}
void View::initscreen() {
	int x = 0; 
	int y = 0;
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



void View::drawMap(int x, int y, int height, int width) {
	for(int i=0; i<width; i++){
		for(int j=0; j<height; j++){
			if((i==0 && j==0) || (i==width-1 && j==0) || (i==0 && j==height-1) || (i==width-1 && j==height-1)){
				move(y+j, x+i);
				printw("+");				
			}else if((i==0) || (i==width-1)){
				move(y+j, x+i);
				printw("|");
			}else if((j==0) || (j==height-1)){
				move(y+j, x+i);
				printw("-");
			}
		}
	}
}

void View::info_commands(int x, int y, int height, int width, char* user, double time, int life, int points) {
	//info
	move(y+5, width+10);
	printw("PLAYER: ");
	printw(user);
	move(y+6, width+10);
	printw("TIME: ");
	printw((char *)"%.2f", time);
	move(y+7, width+10);
	printw("LIFE: ");
	printw((char *)"%d", life);
	move(y+8, width+10);
	printw("POINTS: ");
	printw((char *)"%d", points);
	move(y+9, width+10);
	printw("LEVEL: ");
	move(y+10, width+10);
	printw("ROOM: ");
	move(y+13, width+10);
	printw("@ = bonus");
	move(y+14, width+10);
	printw("<-- = EasyEnemy");
	move(y+15, width+10);
	printw("M = MediumEnemy");
	move(y+16, width+10);
	printw("H = HardEnemy");
	//commands
	move(y+height, x);
	printw("E = shoot || Space = jump || Arrows = move || q = quit"); 
}

void View::drawPlatform(p_plat plat){
	while(plat != __null){
		move(plat->y, plat->x);
		for(int i=1; i<=plat->length; i++){
			printw("=");
			move(plat->y, plat->x+i);
		}	
		plat = plat -> next;
	}
}

/*void View::drawPlatform(int x, int y, int length){
	move(y,x);
	for(int i=1; i<=length; i++){
		printw("=");
		move(y,x+i);
	}
}*/

void View::exitWindow() {
	endwin();
}

void View::printObject(int x, int y, const char* format, char *object) {
	move(y, x);
	printw(format, object);
}

void View::printObject(int x, int y, const char* format, int object) {
	move(y, x);
	printw(format, object);
}

void View::printObject(int x, int y, const char* format, double object) {
	move(y, x);
	printw(format, object);
}

void View::update() {
	refresh();
}

int View::getDelay() {
	return DELAY;
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

void View::game_over(int x, int y){
	move(y,x);
	printw("GAME OVER");
}