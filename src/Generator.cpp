#include "Generator.hpp"

Generator::Generator() {
	currentRoom = 1;
	max_room_generated = 0;
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
	numberPlatforms -= 3;
}

void Generator::createRoom(int room, RoomPosition roomPosition, int width) {
	// STATIC ONLY FOR NOW
	int offset = width * (room-1);
	Platform *p1, *p2, *p3;
	switch (room % 2) {
	case 1:
		p1 = new Platform(3+offset, 6, 7);
		numberPlatforms++;
		p2 = new Platform(7+offset, 5, 7);
		numberPlatforms++;
		p3 = new Platform(25+offset, 6, 9);
		numberPlatforms++;
		break;
	case 0:
		p1 = new Platform(0+offset, 6, 6);
		numberPlatforms++;
		p2 = new Platform(20+offset, 6, 7);
		numberPlatforms++;
		p3 = new Platform(25+offset, 4, 9);
		numberPlatforms++;
		break;
	}
	int index = roomPosition == LEFT_ROOM ? 0 : MAX_PLATFORMS_FOR_ROOM;
	if (roomPosition == LEFT_ROOM && numberPlatforms == 6) {
		for (int i = 0; i < MAX_PLATFORMS_FOR_ROOM; i++) {
			platforms[i+MAX_PLATFORMS_FOR_ROOM] = platforms[i];
		}
	}
	platforms[0+index] = p1;
	platforms[1+index] = p2;
	platforms[2+index] = p3;
}

// PRIVATE
void Generator::addBonus(Bonus *bonus) {
	p_bonus tmp = new bonus_struct;
	tmp->bonus = bonus;
	tmp->next = __null;

	if (bonuses == __null)
		bonuses = tmp;
	else {
		p_bonus iter = bonuses;
		while (iter->next != __null)
			iter = iter->next;
		iter->next = tmp;
		tmp->prev = iter;
	}
}

void Generator::createNewBonuses(int room, int width) {
	if (room > max_room_generated) {
		int offset = width * (room-1);
		// STATIC ONLY FOR NOW
		Bonus *p1 = new Bonus(1+offset, 7, MINIGUN);
		this->addBonus(p1);
		Bonus *p2 = new Bonus(5+offset, 7, INVINCIBILITY);
		this->addBonus(p2);
		max_room_generated = room;
	}
}

void Generator::deleteBonus(Bonus *bonus) {
	p_bonus iter = bonuses;
	bool found = false;
	while (!found) {
		if (iter->bonus == bonus) {
			if (iter == bonuses) {
				bonuses = iter->next;
				delete iter;
			} else {
				iter->prev->next = iter->next;
				delete iter;
			}
			found = true;
		} else {
			iter = iter->next;
		}
	}
}

int Generator::getNumberPlatforms() {
	return numberPlatforms;
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

// STATIC
int Generator::getMaxPlatformsForRoom() {
	return MAX_PLATFORMS_FOR_ROOM;
}
int Generator::getMaxBonusesForRoom() {
	return MAX_BONUSES_FOR_ROOM;
}