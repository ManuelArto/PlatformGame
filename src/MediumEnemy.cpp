#include "MediumEnemy.hpp"

MediumEnemy::MediumEnemy(int x, int y, int points, int life, int attack, double cooldown_shoot, double cooldown_movement, double min_distance_shoot, char *symbol)
						:Character(x, y, points, life, attack, cooldown_shoot, cooldown_movement, symbol) {
	this->min_distance_shoot = min_distance_shoot;
	lastmove_time = 0.0;
}

void MediumEnemy::move(int player_x, double time, int width, int height, bool hasPlatformBelowRight, bool hasPlatformBelowLeft, bool hasPlatformRight, bool hasPlatformLeft) {
	if(time - lastmove_time > cooldown_movement) {
		if (!hasPlatformBelowLeft && !hasPlatformLeft) {
			direction = RIGHT;
		} else if (!hasPlatformBelowRight && !hasPlatformRight) {
			direction = LEFT;
		}
		int movement = direction == LEFT ? KEY_LEFT : KEY_RIGHT;
		Character::move(movement, width, height, time, hasPlatformRight=hasPlatformRight, hasPlatformLeft=hasPlatformLeft);
		lastmove_time = time;
	}
}

void MediumEnemy::shoots(double time, int player_x, int player_y) {
	if (abs(x - player_x) <= min_distance_shoot && y == player_y)
		Character::shoots(time);
}