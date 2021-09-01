#include "Generator.hpp"

Generator::Generator() {
	currentRoom = 1;
}

void Generator::deleteRoom(int room, RoomPosition roomPosition) {
	int index = roomPosition == LEFT_ROOM ? 0 : MAX_PLATFORMS_FOR_ROOM;
	for (int i = index; i < index+MAX_PLATFORMS_FOR_ROOM; i++) {
		delete platforms[i];
	}
	if (roomPosition == LEFT_ROOM) {
		// COSA MINCHIA FA
		currentRoom = room;
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
		currentRoom = room;
		for (int i = 0; i < MAX_PLATFORMS_FOR_ROOM; i++) {
			platforms[i+MAX_PLATFORMS_FOR_ROOM] = platforms[i];
		}
	}
	platforms[0+index] = p1;
	platforms[1+index] = p2;
	platforms[2+index] = p3;
}

void Generator::createBonuses() {
	// STATIC ONLY FOR NOW
	Bonus *p1 = new Bonus(1, 7, MINIGUN);
	numberBonuses++;
	Bonus *p2 = new Bonus(5, 7, INVINCIBILITY);
	numberBonuses++;

	bonuses[0] = p1;
	bonuses[1] = p2;
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

int Generator::getNumberBonuses() {
	return numberBonuses;
}
Bonus *Generator::getBonus(int index) {
	return bonuses[index];
}

int Generator::getCurrentRoom() {
	return currentRoom;
}

int Generator::getMaxPlatformsForRoom() {
	return MAX_PLATFORMS_FOR_ROOM;
}