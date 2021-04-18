#include "Platform.hpp"

class Generator {
private:
	static const int MAX_PLATFORM = 3;
	int numberPlatform = 0;
	Platform *platforms[MAX_PLATFORM];
public:
	Generator();
	void createPlatforms();	// TODO: input room
	int getNumberPlatform();
	Platform **getPlatforms();
	Platform *getPlatform(int index);
};