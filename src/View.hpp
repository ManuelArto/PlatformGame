#include <locale.h>
#if defined(_WIN64) || defined(__WIN32)
	#include <curses.h>
#elif __linux
	#include <ncurses.h>
#endif

class View{
private:
	int width, height;
	const int DELAY = 50;
	const int X_GAME = 3, Y_GAME = 1, GAME_WIDTH = 35, GAME_HEIGHT = 8;
	WINDOW *gamewin;
public:
	void askName(char *setName);
	void clearWindow();
	void createWindow();
	void exitWindow();
	void drawBorders();
	void printInfos(char* user, double time, int life, int points);
	void printPlatform(int x, int y, int length);
	void printObject(int x, int y, const char *format, char *object, bool hasInvincibility=false);
	void printObject(int x, int y, const char *format, int object);
	void printObject(int x, int y, const char *format, double object);
	void update();
	int getKeyboardInput();
	int getWidth();
	int getHeight();	
	int getGameWidth();
	int getGameHeight();
	int getDelay();
};