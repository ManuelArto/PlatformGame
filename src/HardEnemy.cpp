#include "HardEnemy.hpp"

HardEnemy::HardEnemy(int x, int y, int points, int life, int attack, double cooldown_shoot, double cooldown_movement, double min_distance_shoot, char *symbol)
					:Character(x, y, points, life, attack, cooldown_shoot, cooldown_movement, symbol) {
	this->min_distance_shoot = min_distance_shoot;
	direction = LEFT;
	lastmove_time = 0.0;
	findPlatform = false;
}

void HardEnemy::follow(int player_x, int player_y, double time, bool hasPlatformAbove, bool hasPlatformAboveOne, bool hasPlatformBelow, bool hasPlatformBelowOne, bool hasPlatformRight, bool hasPlatformLeft, int width, int height) {
    if(time - lastmove_time > cooldown_movement) {
        if (y <= player_y-2)
			movement = KEY_DOWN;
		else if (y == player_y+1 || (y > player_y+1 && hasPlatformAbove && !hasPlatformAboveOne) && movement != KEY_DOWN) {
			movement = KEY_UP;
			if (hasPlatformAbove)
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
		move(movement, width, height, time, hasPlatformAbove, hasPlatformAboveOne, hasPlatformBelow, hasPlatformBelowOne, hasPlatformRight, hasPlatformLeft);
    }
}

void HardEnemy::shoots(double time, int player_x) {
	if (abs(x - player_x) <= min_distance_shoot)
		Character::shoots(time);
}