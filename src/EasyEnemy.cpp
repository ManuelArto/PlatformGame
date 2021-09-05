#include "EasyEnemy.hpp"

EasyEnemy::EasyEnemy(int x, int y, int level, int points, int life, int attack, double cooldown_movement, char *symbol)
			:Character(x, y, points, life, attack, cooldown_shoot=-1, cooldown_movement, symbol) {
	lastmove_time = 0.0;
	this->attack += INCREMENT_ATTACK * (level/2);
	this->life += INCREMENT_LIFE * (level/2);
	if (this->cooldown_movement - (DECREMENT_COOLDOWN_MOVEMENT * (level/2)) > MIN_COOLDOWN_MOVEMENT)
		this->cooldown_movement -=  DECREMENT_COOLDOWN_MOVEMENT * (level/2);
	else
		this->cooldown_movement = MIN_COOLDOWN_MOVEMENT;
}

//Override
void EasyEnemy::move(int input, int width, int height, double time) {
	if(time - lastmove_time > cooldown_movement){
		lastmove_time = time;
		Character::move(input, width, height, time);
	}
}