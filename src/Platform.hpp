class Platform{
private:
	int x, y, lenght;
public:
	Platform(int x, int y, int lenght);
	int getX();
	int getY();
	int getLenght();
	static bool checkPlatformUp(Platform *platforms[], int numberPlatform, int player_x, int player_y);
	static bool checkPlatformDown(Platform *platforms[], int numberPlatform, int player_x, int player_y);
};