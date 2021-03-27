class Screen{
private:
	int width, height;
	const int DELAY = 50;
public:
	int getWidth();
	int getHeight();
	void clearWindow();
	void createWindow();
	void exitWindow();
	void printObject(int x, int y, char *object);
	void sleep(int delay);
};