#include "Platform.hpp"

class View{
private:
	int width, height;
	const int DELAY = 50;
public:
	void askName(char *setName);
	void clearWindow();
	void createWindow();
	void exitWindow();
	void drawMap(int x, int y, int heigth, int width);
	void drawPlatform(p_plat plat);
	//void drawPlatform(int x, int y, int length);
	void drawInfos(int x, int y, int heigth, int width, char* user, double time, int life, int points);
	void printObject(int x, int y, const char *format, char *object);
	void printObject(int x, int y, const char *format, int object);
	void printObject(int x, int y, const char *format, double object);
	void update();
	int getKeyboardInput();
	int getWidth();
	int getHeight();
	int getDelay();
};