#include "Platform.hpp"

Platform::Platform(int x, int y, int lenght) {
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

bool Platform::checkPlatformAbove(Platform *platforms[], int numberPlatform, int character_x, int character_y) {
    bool flag = false;
	int i = 0;
	while (i < numberPlatform && !flag) {
		Platform *p = platforms[i];
		if (character_y == p->y+1) {
			if (character_x >= p->x && character_x < p->x+p->lenght)
				flag = true;
		}
		i++;
	}
	return flag;
}

bool Platform::checkPlatformBelow(Platform *platforms[], int numberPlatform, int character_x, int character_y) {
	bool flag = false;
	int i = 0;
	while (i < numberPlatform && !flag) {
		Platform *p = platforms[i];
		if (character_y == p->y-1) {
			if (character_x >= p->x && character_x < p->x+p->lenght)
				flag = true;
		}
		i++;
	}
	return flag;
}