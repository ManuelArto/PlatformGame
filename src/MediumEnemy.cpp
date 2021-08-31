#include "MediumEnemy.hpp"

MediumEnemy::MediumEnemy(int x, int y, int points, int life, int attack, double cooldown_shoot, double cooldown_movement, char *symbol)
						:Character(x, y, points, life, attack, cooldown_shoot, cooldown_movement, symbol) {
	lastmove_time = 0.0;
}

void MediumEnemy::follow(int player_x, double time, int width, int height, bool hasPlatformRight, bool hasPlatformLeft) {
	if(time - lastmove_time > cooldown_movement) {
		if (x < player_x && hasPlatformRight) {
			movement = KEY_RIGHT;
		} else if (x > player_x && hasPlatformLeft) {
			movement = KEY_LEFT;
		}
		lastmove_time = time;
		move(movement, width, height, time);
	}
}