#include "MediumEnemy.hpp"

MediumEnemy::MediumEnemy(int x, int y, int points, int life, int attack, double cooldown_shoot, double cooldown_movement, char *symbol, char *mir_symbol)
						:Character(x, y, points, life, attack, cooldown_shoot, symbol, mir_symbol){
			this->cooldown_movement = cooldown_movement;
			lastmove_time = 0.0;
			direction = LEFT;
}

void MediumEnemy::movement(int player_x, int player_y, double time, bool hasPlatformAbove, bool hasPlatformBelow, int width, int height, bool hasPlatformRight, bool hasPlatformLeft){
	int direction = 0;
	if(time - lastmove_time > cooldown_movement){
		if(hasPlatformRight || hasPlatformLeft){
			if(x < player_x){
				direction = KEY_RIGHT;
			}else if(x > player_x){
				direction = KEY_LEFT;
			}
		}
		lastmove_time = time;
	}
	move(direction, width, height, hasPlatformAbove, hasPlatformBelow, time);
}

						