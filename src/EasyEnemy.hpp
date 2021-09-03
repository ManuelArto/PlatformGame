#pragma once

#include "Character.hpp"

class EasyEnemy : public Character{
public:
    EasyEnemy(int x, int y, int points=10, int life=5, int attack=5, double cooldown_movement=0, char *symbol=(char *)"<--");
	// OVERRIDE
	void move(int input, int width, int height, double time);
};
