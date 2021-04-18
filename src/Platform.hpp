class Platform{
private:
	int x, y, lenght;
public:
	Platform(int x, int y, int lenght);
	int getX();
	int getY();
	int getLenght();
	static bool checkPlatformAbove(Platform *platforms[], int numberPlatform, int player_x, int player_y);
	static bool checkPlatformBelow(Platform *platforms[], int numberPlatform, int player_x, int player_y);
};