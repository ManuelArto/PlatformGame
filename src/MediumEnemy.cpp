#include "MediumEnemy.hpp"

MediumEnemy::MediumEnemy(int x, int y, int level, int points, int life, int attack, double cooldown_shoot, double cooldown_movement, double min_distance_shoot, char *symbol)
						:Character(x, y, points, life, attack, cooldown_shoot, cooldown_movement, symbol) {
	lastmove_time = 0.0;
	this->min_distance_shoot = min_distance_shoot;
	if (this->cooldown_movement - (DECREMENT_COOLDOWN_MOVEMENT * (level/2)) > MIN_COOLDOWN_MOVEMENT)
		this->cooldown_movement -= DECREMENT_COOLDOWN_MOVEMENT * (level/2);
	else
		this->cooldown_movement = MIN_COOLDOWN_MOVEMENT;
	this->points += INCREMENT_POINTS * (level/2);
	this->attack += INCREMENT_ATTACK * (level/2);
	this->life += INCREMENT_LIFE * (level/2);
}

void MediumEnemy::move(int player_x, double time, int width, int height, bool hasPlatformBelowRight, bool hasPlatformBelowLeft, bool hasPlatformRight, bool hasPlatformLeft) {
	if(time - lastmove_time > cooldown_movement && abs(player_x - x) <= 30) {
		if (!hasPlatformBelowLeft && !hasPlatformLeft) {
			direction = RIGHT;
		} else if (!hasPlatformBelowRight && !hasPlatformRight) {
			direction = LEFT;
		}
		int movement = direction == LEFT ? KEY_LEFT : KEY_RIGHT;
		Character::move(movement, width, height, time);
		lastmove_time = time;
	}
}

void MediumEnemy::shoots(double time, int player_x, int player_y) {
	if (abs(x - player_x) <= min_distance_shoot && y == player_y)
		Character::shoots(time);
}