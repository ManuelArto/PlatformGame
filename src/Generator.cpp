#include "Generator.hpp"

Generator::Generator() {
	currentRoom = 1;
	rooms_generated = 0;
	cooldown_spawn_easyenemy = 4.0;
	easyEnemies = NULL;
	mediumEnemies = NULL;
	hardEnemies = NULL;
	// PRNG
	seed = time(0);
	srand(seed);
	c = rand();
	d = rand();
	a = 1105;	// PRIME NUMBER
	b = 1729;	// PRIME NUMBER
}

void Generator::deleteRoom(RoomPosition roomPosition) {
	int index = (roomPosition == LEFT_ROOM) ? 0 : MAX_PLATFORMS_FOR_ROOM;
	for (int i = index; i < index+MAX_PLATFORMS_FOR_ROOM; i++) {
		delete platforms[i];
		platforms[i] = NULL;
	}
	// SHIFT ROOM
	if (roomPosition == LEFT_ROOM) {
		for (int i = 0; i < MAX_PLATFORMS_FOR_ROOM; i++) {
			platforms[i] = platforms[i+MAX_PLATFORMS_FOR_ROOM];
		}
	} else {
		for (int i = 0; i < MAX_PLATFORMS_FOR_ROOM; i++) {
			platforms[i+MAX_PLATFORMS_FOR_ROOM] = platforms[i];
		}
	}
}

// PRIVATE
int Generator::getPseudoRandomTemplateNumber(int room) {
	return abs((a*seed + b*room + c) ^ d) % NUMBER_TEMPLATES;
}

void Generator::createRoom(int room, RoomPosition roomPosition, int level, int width) {
	int offset = width * (room-1);
	int index_offset = roomPosition == LEFT_ROOM ? 0 : MAX_PLATFORMS_FOR_ROOM;
	int templateNumber = getPseudoRandomTemplateNumber(room);
	storeNewRoomPlatforms(platforms, index_offset, templateNumber, offset, MAX_PLATFORMS_FOR_ROOM);

	// Generate new Bonuses and new Enemies
	if (room > rooms_generated) {
		this->createNewBonuses(roomPosition, level);
		this->spawnEnemies(roomPosition, level);
		rooms_generated = room;
	}
}

// PRIVATE
void Generator::pickRandomPlatformCoordinates(int coordinates[], RoomPosition roomPosition) {
	int random_offset = roomPosition == LEFT_ROOM ? 0 : MAX_PLATFORMS_FOR_ROOM;
	int index_platform;
	do {
		index_platform = (rand() % MAX_PLATFORMS_FOR_ROOM) + random_offset;
	} while (platforms[index_platform] == NULL ||
			Platform::checkPlatformAbove(platforms, getNumberPlatforms(), platforms[index_platform]->getX(), platforms[index_platform]->getY()));
	int x = platforms[index_platform]->getX() + (rand() % platforms[index_platform]->getLenght());
	int y = platforms[index_platform]->getY() - 1;
	coordinates[0] = x;
	coordinates[1] = y;
}
void Generator::addBonus(Bonus *bonus) {
	p_bonus tmp = new bonus_struct;
	tmp->bonus = bonus;
	tmp->next = bonuses;
	bonuses = tmp;
}
void Generator::createNewBonuses(RoomPosition roomPosition, int level) {
	// PROBABILITY
	int bonusesToSpawn, prob = rand() % 10;
	if (prob >= 0 && prob <= 4)
		bonusesToSpawn = 2;	// 50%
	else if (prob <= 6)
		bonusesToSpawn = 1;	// 20%
	else if (prob == 7)
		bonusesToSpawn = 3;	// 10%
	else
		bonusesToSpawn = 0;	// 20%

	int coordinates[2];
	for (int i = 0; i < bonusesToSpawn; i++) {
		this->pickRandomPlatformCoordinates(coordinates, roomPosition);
		Bonus *p = new Bonus(coordinates[0], coordinates[1], level, rand() % 4);
		this->addBonus(p);
	}
}

void Generator::deleteBonus(Bonus *bonus) {
	p_bonus prev, iter = bonuses;
	bool found = false;
	while (!found) {
		if (iter->bonus == bonus) {
			if (iter == bonuses) {
				bonuses = iter->next;
				delete iter;
			} else {
				prev->next = iter->next;
				delete iter;
			}
			found = true;
		} else {
			prev = iter;
			iter = iter->next;
		}
	}
}

p_enemy Generator::removeEnemy(p_enemy enemiesHead, Character *enemy) {
	p_enemy prev, iter = enemiesHead;
	bool found = false;
	while (!found) {
		if (iter->enemy == enemy) {
			if (iter == enemiesHead) {
				enemiesHead = iter->next;
				delete iter;
			} else {
				prev->next = iter->next;
				delete iter;
			}
			found = true;
		} else {
			prev = iter;
			iter = iter->next;
		}
	}
	return enemiesHead;
}

p_enemy Generator::addEnemy(p_enemy enemiesHead, Character *enemy) {
	p_enemy tmp = new enemy_struct;
	tmp->enemy = enemy;
	tmp->next = enemiesHead;
	return tmp;
}

void Generator::spawnEnemies(RoomPosition roomPosition, int level) {
	int coordinates[2];
	// 1 hardEnemy x Room
	this->pickRandomPlatformCoordinates(coordinates, roomPosition);
	HardEnemy *h = new HardEnemy(coordinates[0], coordinates[1], level);
	hardEnemies = addEnemy(hardEnemies, h);
	// 2 mediumEnemy x Room
	for (int i = 0; i < 2; i++) {
		this->pickRandomPlatformCoordinates(coordinates, roomPosition);
		MediumEnemy *m = new MediumEnemy(coordinates[0], coordinates[1], level);
		mediumEnemies = addEnemy(mediumEnemies, m);
	}
}

// EASY ENEMIES
bool Generator::canSpawnEasyEnemy(double time, int level) {
	if (this->cooldown_spawn_easyenemy - (DECREMENT_COOLDOWN_SPAWN_EASYENEMY * (level/2)) > MIN_COOLDOWN_SPAWN_EASYENEMY)
		this->cooldown_spawn_easyenemy -= DECREMENT_COOLDOWN_SPAWN_EASYENEMY * (level/2);
	else
		this->cooldown_spawn_easyenemy = MIN_COOLDOWN_SPAWN_EASYENEMY;
	return (time - lastSpawnEasyEnemy_time > cooldown_spawn_easyenemy);
}
void Generator::spawnEasyEnemy(int width, int offset, int player_y, int level, double time) {
	EasyEnemy *enemy = new EasyEnemy(width+offset-4, player_y, level);
	easyEnemies = addEnemy(easyEnemies, enemy);
	lastSpawnEasyEnemy_time = time;
}
void Generator::initEasyEnemyIterator() {
	easyEnemies_iter = easyEnemies;
}
bool Generator::hasNextEasyEnemy() {
	return (easyEnemies_iter != NULL);
}
EasyEnemy *Generator::getNextEasyEnemy() {
	EasyEnemy *tmp = (EasyEnemy *)easyEnemies_iter->enemy;
	easyEnemies_iter = easyEnemies_iter->next;
	return tmp;
}
void Generator::removeEasyEnemy(EasyEnemy *enemy) {
	easyEnemies = this->removeEnemy(easyEnemies, enemy);
}
p_enemy Generator::getEasyEnemiesHead() {
	return easyEnemies;
}

// MEDIUM ENEMIES
void Generator::initMediumEnemyIterator() {
	mediumEnemies_iter = mediumEnemies;
}
bool Generator::hasNextMediumEnemy() {
	return (mediumEnemies_iter != NULL);
}
MediumEnemy *Generator::getNextMediumEnemy() {
	MediumEnemy *tmp = (MediumEnemy *)mediumEnemies_iter->enemy;
	mediumEnemies_iter = mediumEnemies_iter->next;
	return tmp;
}
void Generator::removeMediumEnemy(MediumEnemy *enemy) {
	mediumEnemies = this->removeEnemy(mediumEnemies, enemy);
}
p_enemy Generator::getMediumEnemiesHead() {
	return mediumEnemies;
}

// HARD ENEMIES
void Generator::initHardEnemyIterator() {
	hardEnemies_iter = hardEnemies;
}
bool Generator::hasNextHardEnemy() {
	return (hardEnemies_iter != NULL);
}
HardEnemy *Generator::getNextHardEnemy() {
	HardEnemy *tmp = (HardEnemy *)hardEnemies_iter->enemy;
	hardEnemies_iter = hardEnemies_iter->next;
	return tmp;
}
void Generator::removeHardEnemy(HardEnemy *enemy) {
	hardEnemies = this->removeEnemy(hardEnemies, enemy);
}
p_enemy Generator::getHardEnemiesHead() {
	return hardEnemies;
}

int Generator::getNumberPlatforms() {
	return MAX_PLATFORMS_FOR_ROOM*2;
}
Platform *Generator::getPlatform(int index) {
	return platforms[index];
}
Platform **Generator::getPlatforms() {
	return platforms;
}
p_bonus Generator::getBonuses() {
	return bonuses;
}
void Generator::setCurrentRoom(int room) {
	this->currentRoom = room;
}
int Generator::getCurrentRoom() {
	return currentRoom;
}