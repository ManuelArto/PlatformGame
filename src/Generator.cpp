#include "Generator.hpp"

Generator::Generator() {}

void Generator::createPlatforms() {
	// STATIC ONLY FOR NOW
	Platform *p1 = new Platform(3, 6, 5);
	numberPlatform++;
	Platform *p2 = new Platform(11, 2, 5);
	numberPlatform++;
	Platform *p3 = new Platform(7, 4, 5);
	numberPlatform++;

	platforms[0] = p1;
	platforms[1] = p2;
	platforms[2] = p3;
}

void Generator::createBonuses() {
	// STATIC ONLY FOR NOW
	Bonus *p1 = new Bonus(1, 7, LIFE);
	numberBonus++;

	bonuses[0] = p1;
}

int Generator::getNumberPlatform() {
	return numberPlatform;
}
Platform *Generator::getPlatform(int index) {
	return platforms[index];
}
Platform **Generator::getPlatforms() {
	return platforms;
}

int Generator::getNumberBonus() {
	return numberBonus;
}
Bonus *Generator::getBonus(int index) {
	return bonuses[index];
}
	