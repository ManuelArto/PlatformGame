#include "HardEnemy.hpp"

HardEnemy::HardEnemy(int x, int y, int points, int life, int attack, double cooldown, double cooldown_jump, char *symbol, char *mir_symbol)
					:Character(x, y, points, life, attack, cooldown, cooldown_jump, symbol, mir_symbol) {
	lastmove_time = 0.0;
	findPlatform = false;
}

void HardEnemy::follow(int player_x, int player_y, double time, bool hasPlatformAbove, bool hasPlatformBelow, int width, int height) {
    if(time - lastmove_time > cooldown) {
        int direction = 0;
        if (y < player_y)
			direction = KEY_DOWN;
        else if ((y > player_y && hasPlatformAbove) || y == player_y+1) {
			direction = KEY_UP;
			findPlatform = false;
		} else if (x != player_x && !findPlatform) {
			direction = x < player_x ? KEY_RIGHT : KEY_LEFT;
			last_direction = direction;
		} else if (findPlatform || (x == player_x && y > player_y)){
			if (x == width-1)
				direction = KEY_LEFT;
			else if (x == 0)
				direction = KEY_RIGHT;
			else
				direction = last_direction;
			findPlatform = y != player_y;
			last_direction = direction;
		}

		move(direction, width, height, hasPlatformAbove, hasPlatformBelow, time);
		lastmove_time = time;
    }
}