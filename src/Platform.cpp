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

// STATIC

bool Platform::checkPlatformAbove(Platform *platforms[], int numberPlatform, int character_x, int character_y) {
    bool hasPlatformAbove = false;
	int i = 0;
	while (i < numberPlatform && !hasPlatformAbove) {
		Platform *p = platforms[i];
		if (character_y == p->y+1) {
			if (character_x >= p->x && character_x < p->x+p->lenght)
				hasPlatformAbove = true;
		}
		i++;
	}
	return hasPlatformAbove;
}

bool Platform::checkPlatformBelow(Platform *platforms[], int numberPlatform, int character_x, int character_y, double height) {
	bool hasPlatformBelow = false;
	int i = 0;
	while (i < numberPlatform && !hasPlatformBelow) {
		Platform *p = platforms[i];
		if (character_y == p->y-1) {
			if (character_x >= p->x && character_x < p->x+p->lenght)
				hasPlatformBelow = true;
		}
		i++;
	}
	return hasPlatformBelow || character_y == height-1;
}


bool Platform::checkPlatformRight(Platform *platforms[], int numberPlatform, int character_x, int character_y) {
	bool hasPlatformRight = false;
	int i = 0;
	while (i < numberPlatform && !hasPlatformRight) {
		Platform *p = platforms[i];
		if (character_y == p->y && character_x == p->x-1) {
			hasPlatformRight = true;
		}
		i++;
	}
	return hasPlatformRight;
}

bool Platform::checkPlatformLeft(Platform *platforms[], int numberPlatform, int character_x, int character_y) {
	bool hasPlatformLeft = false;
	int i = 0;
	while (i < numberPlatform && !hasPlatformLeft) {
		Platform *p = platforms[i];
		if (character_y == p->y && character_x == p->x+p->lenght) {
			hasPlatformLeft = true;
		}
		i++;
	}
	return hasPlatformLeft;
}