#include "Platform.hpp"

Platform::Platform(int x, int y, int lenght){
    this->x = x;
	this->y = y;
	this->lenght = lenght;
}

int Platform::getX() {
	return x;
}
int Platform::getY() {
	return y;
}
int Platform::getLenght() {
	return lenght;
}

bool Platform::checkPlatformAbove(Platform *platforms[], int numberPlatform, int player_x, int player_y){
    bool flag = false;
	for (int i = 0; i < numberPlatform && !flag; i++) {
		Platform *p = platforms[i];
		if (player_y == p->y+1) {
			if (player_x >= p->x && player_x < p->x+p->lenght)
				flag = true;
		}
	}
	return flag;
}

bool Platform::checkPlatformBelow(Platform *platforms[], int numberPlatform, int player_x, int player_y){
    bool flag = false;
	for (int i = 0; i < numberPlatform && !flag; i++) {
		Platform *p = platforms[i];
		if (player_y == p->y-1) {
			if (player_x >= p->x && player_x < p->x+p->lenght)
				flag = true;
		}
	}
	return flag;
}