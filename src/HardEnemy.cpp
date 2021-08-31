#include "HardEnemy.hpp"

HardEnemy::HardEnemy(int x, int y, int points, int life, int attack, double cooldown_shoot, double cooldown_movement, char *symbol)
					:Character(x, y, points, life, attack, cooldown_shoot, cooldown_movement, symbol) {
	direction = LEFT;
	lastmove_time = 0.0;
	findPlatform = false;
}

void HardEnemy::follow(int player_x, int player_y, double time, bool hasPlatformAbove, bool hasPlatformBelow, int width, int height) {
    if(time - lastmove_time > cooldown_movement) {
        if (y < player_y)
			movement = KEY_DOWN;
        else if ((y >= player_y+2 && hasPlatformAbove) || (y == player_y+1 && !hasPlatformAbove)) {
			movement = KEY_UP;
			findPlatform = false;
		} else if (x != player_x && !findPlatform) {
			movement = x < player_x ? KEY_RIGHT : KEY_LEFT;
		} else if (findPlatform || (x == player_x && y > player_y)) {
			if (x == width-1)
				movement = KEY_LEFT;
			else if (x == 0)
				movement = KEY_RIGHT;
			findPlatform = (y != player_y);
		}
		lastmove_time = time;
		move(movement, width, height, time, hasPlatformAbove, hasPlatformBelow);
    }
}