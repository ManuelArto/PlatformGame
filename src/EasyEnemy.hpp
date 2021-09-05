#pragma once

#include "Character.hpp"

class EasyEnemy : public Character{
public:
    EasyEnemy(int x, int y, int points=0, int life=20, int attack=10, double cooldown_movement=0.2, char *symbol=(char *)"<--");
	// OVERRIDE
	void move(int input, int width, int height, double time);
};
