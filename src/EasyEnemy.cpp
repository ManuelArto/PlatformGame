#include "EasyEnemy.hpp"

EasyEnemy::EasyEnemy(int x, int y, int level, int points, int life, int attack, double cooldown_movement, char *symbol)
			:Character(x, y, points, life, attack, cooldown_shoot=-1, cooldown_movement, symbol) {
	lastmove_time = 0.0;
	this->attack += INCREMENT_ATTACK * (level/2);
}

//Override
void EasyEnemy::move(int input, int width, int height, double time) {
	if(time - lastmove_time > cooldown_movement){
		lastmove_time = time;
		Character::move(input, width, height, time);
	}
}