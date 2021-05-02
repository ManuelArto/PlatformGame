#include <cstring>
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
	const int START_X_GAME = 3, START_Y_GAME = 2, GAME_WIDTH = 35, GAME_HEIGHT = 8;
	WINDOW *gamewin;
public:
	void askName(char *setName);
	void clearWindow();
	void createWindow();
	void exitWindow();
	void printLoadingGame();
	void printGameOver();
	void drawBorders();
	void printInfos(char* username, double time, int life, int points, int level, double invincibility_timer, double minigun_timer);
	void printPlatform(int x, int y, int length, int offset);
	void printObject(int x, int y, const char *format, char *object, int offset, bool hasInvincibility=false);
	void printObject(int x, int y, const char *format, int object, int offset);
	void printObject(int x, int y, const char *format, double object, int offset);
	void update();
	int getKeyboardInput();
	int getWidth();
	int getHeight();	
	int getGameWidth();
	int getGameHeight();
	int getDelay();
};