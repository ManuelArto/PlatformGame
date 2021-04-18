#include "Generator.hpp"

Generator::Generator(){}

void Generator::createPlatforms() {
	// STATIC ONLY FOR NOW
	Platform *p1 = new Platform(3, 6, 4);
	numberPlatform++;
	Platform *p2 = new Platform(9, 6, 3);
	numberPlatform++;

	platforms[0] = p1;
	platforms[1] = p2;
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