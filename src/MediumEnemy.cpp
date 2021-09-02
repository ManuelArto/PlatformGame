#include "MediumEnemy.hpp"

MediumEnemy::MediumEnemy(int x, int y, int points, int life, int attack, double cooldown_shoot, double cooldown_movement, double min_distance_shoot, char *symbol)
						:Character(x, y, points, life, attack, cooldown_shoot, cooldown_movement, symbol) {
	this->min_distance_shoot = min_distance_shoot;
	lastmove_time = 0.0;
}

void MediumEnemy::follow(int player_x, double time, int width, int height, bool hasPlatformBelowRight, bool hasPlatformBelowLeft, bool hasPlatformRight, bool hasPlatformLeft) {
	if(time - lastmove_time > cooldown_movement) {
		if (x < player_x && hasPlatformBelowRight) {
			move(KEY_RIGHT, width, height, time, hasPlatformRight=hasPlatformRight, hasPlatformLeft=hasPlatformLeft);
		} else if (x > player_x && hasPlatformBelowLeft) {
			move(KEY_LEFT, width, height, time, hasPlatformRight=hasPlatformRight, hasPlatformLeft=hasPlatformLeft);
		}
		lastmove_time = time;
	}
}

void MediumEnemy::shoots(double time, int player_x) {
	if (abs(x - player_x) <= min_distance_shoot)
		Character::shoots(time);
}