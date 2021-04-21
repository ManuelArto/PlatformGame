#include "Platform.hpp"
#include "Bonus.hpp"

enum RoomPosition {LEFT_ROOM, RIGHT_ROOM};

class Generator {
private:
	static const int MAX_PLATFORMS_FOR_ROOM = 3, MAX_BONUSES_FOR_ROOM = 3;
	int currentRoom;
	int numberPlatforms = 0, numberBonuses = 0;
	Platform *platforms[MAX_PLATFORMS_FOR_ROOM*2];
	Bonus *bonuses[MAX_BONUSES_FOR_ROOM*2];
public:
	static int getMaxPlatformsForRoom();
	Generator();
	void deleteRoom(int room, RoomPosition roomPosition);
	void createRoom(int room, RoomPosition roomPosition, int width);
	int getNumberPlatforms();
	Platform *getPlatform(int index);
	Platform **getPlatforms();
	void createBonuses();
	int getNumberBonuses();
	Bonus *getBonus(int index);
	int getCurrentRoom();
};