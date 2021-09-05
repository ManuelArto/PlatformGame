#pragma once

#include "Character.hpp"

class EasyEnemy : public Character {
private:
	static const int INCREMENT_ATTACK = 5;
public:
    EasyEnemy(int x, int y, int level, int points=0, int life=20, int attack=10, double cooldown_movement=0, char *symbol=(char *)"<--");
	// OVERRIDE
	void move(int input, int width, int height, double time);
};
