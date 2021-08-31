#include "MediumEnemy.hpp"

MediumEnemy::MediumEnemy(int x, int y, int points, int life, int attack, double cooldown_shoot, double cooldown_movement, char *symbol)
						:Character(x, y, points, life, attack, cooldown_shoot, cooldown_movement, symbol) {
	lastmove_time = 0.0;
}

void MediumEnemy::follow(int player_x, double time, int width, int height, bool hasPlatformRight, bool hasPlatformLeft) {
	if(time - lastmove_time > cooldown_movement) {
		if (x < player_x && hasPlatformRight) {
			move(KEY_RIGHT, width, height, time);
		} else if (x > player_x && hasPlatformLeft) {
			move(KEY_LEFT, width, height, time);
		}
		lastmove_time = time;
	}
}

void MediumEnemy::shoots(double time, int player_x, double distance) {
	if (abs(x - player_x) <= distance)
		Character::shoots(time);
}