class View{
private:
	int width, height;
	const int DELAY = 50;
public:
	void clearWindow();
	void createWindow();
	void exitWindow();
	void update();
	void initscreen();
	char* getName();
	void drawMap(int x, int y, int heigth, int width);
	void info_commands(int x, int y, int heigth, int width, char* user, double time);
	void printObject(int x, int y, const char *format, char *object);
	void printObject(int x, int y, const char *format, int object);
	void printObject(int x, int y, const char *format, double object);
	int getKeyboardInput();
	int getWidth();
	int getHeight();
	int getDelay();
	void game_over(int x, int y);
};