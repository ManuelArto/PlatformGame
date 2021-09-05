#include <cstring>
#if defined(_WIN64) || defined(__WIN32)
	#include <curses.h>
#elif __linux
	#include <ncurses.h>
#endif

#define INVINCIBILITY_COLOR 1
#define GAME_INFO_COLOR 2
#define PLAYER_INFO_COLOR 3
#define ERROR_MESSAGE 4

class View {
private:
	int width, height;
	const int DELAY = 50;
	const int START_X_GAME = 3, START_Y_GAME = 2, GAME_WIDTH = 50, GAME_HEIGHT = 8;
	WINDOW *gamewin;
	void printWithAttr(char *label, unsigned int attr, WINDOW *win=stdscr);
	void printErrorDimensions();
	void printGameInfos(int level, int room, double time, int &y_offset);
	void printPlayerInfos(char *username, int life, int points, double invincibility_timer, double minigun_timer, int &y_offset);
	void printLegenda(int &y_offset);
	void printCommands(int &y_offset);
public:
	void createWindow();
	void checkDimensions();
	void askName(char *setName, const int MAX_NAME_LENGHT);
	void drawBorders();
	void printInfos(char* username, int room, double time, int life, int points, int level, double invincibility_timer, double minigun_timer);
	void printPlatform(int x, int y, int length, int offset);
	void printObject(int x, int y, const char *format, char *label, int offset, bool hasInvincibility=false, bool isDamaged=false);
	void printObject(int x, int y, const char *format, int label, int offset);
	void printObject(int x, int y, const char *format, double label, int offset);
	void update();
	void clearWindow();
	void exitWindow();
	void printGameName();
	void printLoadingGame();
	void printGameOver(int points, double time);
	int getKeyboardInput();
	int getWidth();
	int getHeight();	
	int getGameWidth();
	int getGameHeight();
	int getDelay();
};