class View{
private:
	int width, height;
	const int DELAY = 50;
public:
	void clearWindow();
	void createWindow();
	void exitWindow();
	void update();
	void drawMap();
	void printObject(int x, int y, const char *format, char *object);
	void printObject(int x, int y, const char *format, double object);
	int getKeyboardInput();
	int getWidth();
	int getHeight();
	int getDelay();
};