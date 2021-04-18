#include "HardEnemy.hpp"

HardEnemy::HardEnemy(int x, int y, int points, int life, int attack, double cooldown, char *symbol, char *mir_symbol):Character(x, y, points, life, attack, cooldown, symbol, mir_symbol) {
	lastmove_time = 0.0;
	findPlatform = false;
}

void HardEnemy::follow(int player_x, int player_y, double time, bool hasPlatformAbove, bool hasPlatformBelow, int width, int height) {
    if(time - lastmove_time > 0.2) {
        int direction = 0;
        if (y < player_y)
			direction = KEY_DOWN;
        else if (y > player_y && hasPlatformAbove) {
			direction = KEY_UP;
			findPlatform = false;
		} else if (x != player_x && !findPlatform) {
			direction = x < player_x ? KEY_RIGHT : KEY_LEFT;
			last_direction = direction;
		} else if (findPlatform || (x == player_x && y > player_y)){
			direction = last_direction;
			findPlatform = true;
		}

		move(direction, width, height, hasPlatformAbove, hasPlatformBelow);
		lastmove_time = time;
    }
}