#include "HardEnemy.hpp"

HardEnemy::HardEnemy(int x, int y, int points, int life, int attack, double cooldown_shoot, double cooldown_movement, char *symbol, char *mir_symbol)
					: Character(x, y, points, life, attack, cooldown_shoot, symbol, mir_symbol) {
	direction = LEFT;
	this->cooldown_movement = cooldown_movement;
	lastmove_time = 0.0;
	findPlatform = false;
}

void HardEnemy::follow(int player_x, int player_y, double time, bool hasPlatformAbove, bool hasPlatformBelow, int width, int height) {
	int direction = 0;
    if(time - lastmove_time > cooldown_movement) {
        if (y < player_y && !jumping)
			direction = KEY_DOWN;
        else if ((y == player_y+2 && hasPlatformAbove) || (y == player_y+1 && !hasPlatformAbove)) {
			direction = KEY_UP;
			findPlatform = false;
		} else if (x != player_x && !findPlatform) {
			direction = x < player_x ? KEY_RIGHT : KEY_LEFT;
			last_direction = direction;
		} else if (findPlatform || (x == player_x && y > player_y)) {
			if (x == width-1)
				direction = KEY_LEFT;
			else if (x == 0)
				direction = KEY_RIGHT;
			else
				direction = last_direction;
			findPlatform = y != player_y;
			last_direction = direction;
		}

		lastmove_time = time;
    }
	move(direction, width, height, hasPlatformAbove, hasPlatformBelow, time);
}