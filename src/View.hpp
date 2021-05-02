#include <cstring>
#include <locale.h>
#if defined(_WIN64) || defined(__WIN32)
	#include <curses.h>
#elif __linux
	#include <ncurses.h>
#endif

#define DEFAULT_COLOR 0
#define INVINCIBILITY_COLOR 1
#define GAME_INFO_COLOR 2
#define PLAYER_INFO_COLOR 3

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
	void printWithColor(char *label, int color_pair=DEFAULT_COLOR);
	void printPlatform(int x, int y, int length, int offset);
	void printObject(int x, int y, const char *format, char *label, int offset, bool hasInvincibility=false);
	void printObject(int x, int y, const char *format, int label, int offset);
	void printObject(int x, int y, const char *format, double label, int offset);
	void update();
	int getKeyboardInput();
	int getWidth();
	int getHeight();	
	int getGameWidth();
	int getGameHeight();
	int getDelay();
};