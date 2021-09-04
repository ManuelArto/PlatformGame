#include <cstdlib>
#include <ctime>

#include "EasyEnemy.hpp"
#include "MediumEnemy.hpp"
#include "HardEnemy.hpp"
#include "Platform.hpp"
#include "Bonus.hpp"
#include "PlatformsData.hpp"

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
	static const int MAX_PLATFORMS_FOR_ROOM = 12, MAX_BONUSES_FOR_ROOM = 3, MAX_ENEMIES_FOR_ROOM = 3;
	int seed, a, b, c, d;	// USED FOR PRNG (Pseudo Random Number Generator)
	int currentRoom, rooms_generated;
	int numberPlatforms = 0;
	double cooldown_spawn_easyenemy, lastSpawnEasyEnemy_time;
	p_enemy easyEnemies, easyEnemies_iter, mediumEnemies, mediumEnemies_iter, hardEnemies, hardEnemies_iter;
	Platform *platforms[MAX_PLATFORMS_FOR_ROOM*2];
	p_bonus bonuses;
	void addBonus(Bonus *bonus);
	void createNewBonuses(int room, int offset);
	p_enemy addEnemy(p_enemy enemiesHead, Character *enemy);
	p_enemy removeEnemy(p_enemy enemiesHead, Character *enemy);
	void spawnEnemies(int room, int offset);
public:
	int getPseudoRandomTemplateNumber(int room);
	Generator();
	// ROOM
	void deleteRoom(RoomPosition roomPosition);
	void createRoom(int room, RoomPosition roomPosition, int width);
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
	bool canSpawnEasyEnemy(double time);
	void spawnEasyEnemy(int width, int offset, int player_y, double time);
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