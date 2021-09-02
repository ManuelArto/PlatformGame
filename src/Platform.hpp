#pragma once

class Platform{
private:
	int x, y, lenght;
public:
	Platform(int x, int y, int lenght);
	int getX();
	int getY();
	int getLenght();
	static bool checkPlatformAbove(Platform *platforms[], int numberPlatform, int character_x, int character_y);
	static bool checkPlatformBelow(Platform *platforms[], int numberPlatform, int character_x, int character_y, double height);
	static bool checkPlatformRight(Platform *platforms[], int numberPlatform, int character_x, int character_y);
	static bool checkPlatformLeft(Platform *platforms[], int numberPlatform, int character_x, int character_y);
};