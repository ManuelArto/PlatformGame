#include <cstdlib>
#include <ctime>

#include "../model/characters/EasyEnemy.hpp"
#include "../model/characters/MediumEnemy.hpp"
#include "../model/characters/HardEnemy.hpp"
#include "../model/Platform.hpp"
#include "../model/Bonus.hpp"
#include "../template/PlatformsData.cpp"

enum RoomPosition {LEFT_ROOM, RIGHT_ROOM};

struct enemy_struct {
	Character *enemy;
	enemy_struct *next;
};
typedef enemy_struct *p_enemy;

struct bonus_struct {
	Bonus *bonus;
	bonus_struct *next;
};
typedef bonus_struct *p_bonus;

class Generator {
private:
	static const int MAX_PLATFORMS_FOR_ROOM = 12;
	const int DECREMENT_COOLDOWN_SPAWN_EASYENEMY = 1, MIN_COOLDOWN_SPAWN_EASYENEMY = 1;
	int seed, a, b, c, d;	// USED FOR PRNG (Pseudo Random Number Generator)
	int currentRoom, rooms_generated;
	double cooldown_spawn_easyenemy, lastSpawnEasyEnemy_time;
	p_enemy easyEnemies, easyEnemies_iter, mediumEnemies, mediumEnemies_iter, hardEnemies, hardEnemies_iter;
	Platform *platforms[MAX_PLATFORMS_FOR_ROOM*2];
	p_bonus bonuses;
	void pickRandomPlatformCoordinates(int coordinates[], RoomPosition roomPosition);
	void addBonus(Bonus *bonus);
	void createNewBonuses(RoomPosition roomPosition, int level);
	p_enemy addEnemy(p_enemy enemiesHead, Character *enemy);
	p_enemy removeEnemy(p_enemy enemiesHead, Character *enemy);
	void spawnEnemies(RoomPosition roomPosition, int level);
	int getPseudoRandomTemplateNumber(int room);
public:
	Generator();
	// ROOM
	void deleteRoom(RoomPosition roomPosition);
	void createRoom(int room, RoomPosition roomPosition, int level, int width);
	void setCurrentRoom(int room);
	int getCurrentRoom();
	// PLATFORMS
	int getNumberPlatforms();
	Platform *getPlatform(int index);
	Platform **getPlatforms();
	// BONUSES
	void deleteBonus(Bonus *bonus);
	p_bonus getBonuses();
	// EASY ENEMIES
	bool canSpawnEasyEnemy(double time, int level);
	void spawnEasyEnemy(int width, int offset, int player_y, int level, double time);
	void initEasyEnemyIterator();
	bool hasNextEasyEnemy();
	EasyEnemy *getNextEasyEnemy();
	void removeEasyEnemy(EasyEnemy *enemy);
	p_enemy getEasyEnemiesHead();
	// MEDIUM ENEMIES
	void initMediumEnemyIterator();
	bool hasNextMediumEnemy();
	MediumEnemy *getNextMediumEnemy();
	void removeMediumEnemy(MediumEnemy *enemy);
	p_enemy getMediumEnemiesHead();
	// HARD ENEMIES
	void initHardEnemyIterator();
	bool hasNextHardEnemy();
	HardEnemy *getNextHardEnemy();
	void removeHardEnemy(HardEnemy *enemy);
	p_enemy getHardEnemiesHead();
};