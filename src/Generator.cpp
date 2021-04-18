#include "Generator.hpp"

Generator::Generator(){}

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

int Generator::getNumberPlatform() {
	return numberPlatform;
}
Platform **Generator::getPlatforms() {
	return platforms;
}
Platform *Generator::getPlatform(int index) {
	return platforms[index];
}