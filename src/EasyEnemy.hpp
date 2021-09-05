#pragma once

#include "Character.hpp"

class EasyEnemy : public Character {
private:
	static const int DECREMENT_COOLDOWN_MOVEMENT = 0.1, MIN_COOLDOWN_MOVEMENT = 0.1, INCREMENT_ATTACK = 5, INCREMENT_LIFE = 5;
public:
    EasyEnemy(int x, int y, int level, int points=0, int life=20, int attack=10, double cooldown_movement=0.2, char *symbol=(char *)"<--");
	// OVERRIDE
	void move(int input, int width, int height, double time);
};
