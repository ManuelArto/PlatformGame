#include "Platform.hpp"
#include "Bonus.hpp"

class Generator {
private:
	static const int MAX_PLATFORM = 3, MAX_BONUS = 3;
	int numberPlatform = 0, numberBonus = 0;
	Platform *platforms[MAX_PLATFORM];
	Bonus *bonuses[MAX_BONUS];
public:
	Generator();
	void createPlatforms();	// TODO: input room
	int getNumberPlatform();
	Platform *getPlatform(int index);
	Platform **getPlatforms();
	void createBonuses();	// TODO: input room
	int getNumberBonus();
	Bonus *getBonus(int index);
};