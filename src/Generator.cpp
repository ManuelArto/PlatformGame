#include "Generator.hpp"

Generator::Generator() {
	currentRoom = 1;
	rooms_generated = 0;
	cooldown_spawn_easyenemy = 3.0;
	easyEnemies = __null;
	mediumEnemies = __null;
	hardEnemies = __null;
}

void Generator::deleteRoom(RoomPosition roomPosition) {
	int index = (roomPosition == LEFT_ROOM) ? 0 : MAX_PLATFORMS_FOR_ROOM;
	for (int i = index; i < index+MAX_PLATFORMS_FOR_ROOM; i++) {
		delete platforms[i];
	}
	if (roomPosition == LEFT_ROOM) {
		for (int i = 0; i < MAX_PLATFORMS_FOR_ROOM; i++) {
			platforms[i] = platforms[i+MAX_PLATFORMS_FOR_ROOM];
		}
	}
}

void Generator::createRoom(int room, RoomPosition roomPosition, int width) {
	int offset = width * (room-1);
	// Generate new Bonuses and new Enemies
	if (room > rooms_generated) {
		this->createNewBonuses(room, offset);
		this->spawnEnemies(room, offset);
		rooms_generated = room;
	}
	int index = roomPosition == LEFT_ROOM ? 0 : MAX_PLATFORMS_FOR_ROOM;
	if (roomPosition == LEFT_ROOM) {
		for (int i = 0; i < MAX_PLATFORMS_FOR_ROOM; i++) {
			platforms[i+MAX_PLATFORMS_FOR_ROOM] = platforms[i];
		}
	}
	Platform *newPlatformsRoom[MAX_PLATFORMS_FOR_ROOM];
	getRoomPlatforms((room-1) % 10, offset, newPlatformsRoom, MAX_PLATFORMS_FOR_ROOM);
	for (int i = 0; i < MAX_PLATFORMS_FOR_ROOM; i++) {
		platforms[i+index] = newPlatformsRoom[i];
	}
}

// PRIVATE
void Generator::addBonus(Bonus *bonus) {
	p_bonus tmp = new bonus_struct;
	tmp->bonus = bonus;
	tmp->next = bonuses;
	bonuses = tmp;
}
void Generator::createNewBonuses(int room, int offset) {
	// STATIC ONLY FOR NOW
	Bonus *p1 = new Bonus(1+offset, 7, MINIGUN);
	this->addBonus(p1);
	Bonus *p2 = new Bonus(5+offset, 7, INVINCIBILITY);
	this->addBonus(p2);
	rooms_generated = room;
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

void Generator::spawnEnemies(int room, int offset) {
	if (room == 1) {
		HardEnemy *h = new HardEnemy(47+offset, 7);
		hardEnemies = addEnemy(hardEnemies, h);
		MediumEnemy *m = new MediumEnemy(10+offset, 4);
		mediumEnemies = addEnemy(mediumEnemies, m);
	}
}

// EASY ENEMIES
bool Generator::canSpawnEasyEnemy(double time) {
	return (time - lastSpawnEasyEnemy_time > cooldown_spawn_easyenemy);
}
void Generator::spawnEasyEnemy(int width, int offset, int player_y, double time) {
	EasyEnemy *enemy = new EasyEnemy(width+offset-3, player_y);
	easyEnemies = addEnemy(easyEnemies, enemy);
	lastSpawnEasyEnemy_time = time;
}
void Generator::initEasyEnemyIterator() {
	easyEnemies_iter = easyEnemies;
}
bool Generator::hasNextEasyEnemy() {
	return (easyEnemies_iter != __null);
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
	return (mediumEnemies_iter != __null);
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
	return (hardEnemies_iter != __null);
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