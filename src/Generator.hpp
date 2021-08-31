#include <cstdlib>

#include "Platform.hpp"
#include "Bonus.hpp"

enum RoomPosition {LEFT_ROOM, RIGHT_ROOM};

struct bonus_struct{
	Bonus *bonus;
	bonus_struct *next, *prev;
};
typedef bonus_struct *p_bonus;

class Generator {
private:
	static const int MAX_PLATFORMS_FOR_ROOM = 3, MAX_BONUSES_FOR_ROOM = 3;
	int currentRoom, max_room_generated;
	int numberPlatforms = 0;
	Platform *platforms[MAX_PLATFORMS_FOR_ROOM*2];
	p_bonus bonuses;
	void addBonus(Bonus *bonus);
public:
	static int getMaxPlatformsForRoom();
	static int getMaxBonusesForRoom();
	Generator();
	void deleteRoom(RoomPosition roomPosition);
	void createRoom(int room, RoomPosition roomPosition, int width);
	int getNumberPlatforms();
	Platform *getPlatform(int index);
	Platform **getPlatforms();
	void createNewBonuses(int room, int width);
	void deleteBonus(Bonus *bonus);
	p_bonus getBonuses();
	void setCurrentRoom(int room);
	int getCurrentRoom();
};