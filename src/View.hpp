class View{
private:
	int width, height;
	const int DELAY = 50;
public:
	int getWidth();
	int getHeight();
	void clearWindow();
	void createWindow();
	void exitWindow();
	void update();
	void drawMap();
	void printObject(int x, int y, char *object);
	int getKeyboardInput();
};