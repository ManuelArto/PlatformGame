#include "HardEnemy.hpp"

HardEnemy::HardEnemy(int x, int y, int level, int points, int life, int attack, double cooldown_shoot, double cooldown_movement, double min_distance_shoot, char *symbol)
					:Character(x, y, points, life, attack, cooldown_shoot, cooldown_movement, symbol) {
	direction = LEFT;
	lastmove_time = 0.0;
	findPlatform = false;
	this->min_distance_shoot = min_distance_shoot;
	if (this->cooldown_movement - (DECREMENT_COOLDOWN_MOVEMENT * (level/2)) > MIN_COOLDOWN_MOVEMENT)
		this->cooldown_movement -= DECREMENT_COOLDOWN_MOVEMENT * (level/2);
	else
		this->cooldown_movement = MIN_COOLDOWN_MOVEMENT;
	this->points += INCREMENT_POINTS * (level/2);
	this->attack += INCREMENT_ATTACK * (level/2);
	this->life += INCREMENT_LIFE * (level/2);
}

void HardEnemy::follow(int player_x, int player_y, double time, bool hasPlatformAbove, bool hasPlatformAboveOne, bool hasPlatformBelow, bool hasPlatformBelowOne, bool hasPlatformRight, bool hasPlatformLeft, int width, int height) {
    if(time - lastmove_time > cooldown_movement && abs(player_x - x) <= 20) {
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