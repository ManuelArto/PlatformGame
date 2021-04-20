#include "MediumEnemy.hpp"

MediumEnemy::MediumEnemy(int x, int y, int points, int life, int attack, double cooldown_shoot, double cooldown_movement, char *symbol, char *mir_symbol)
						:Character(x, y, points, life, attack, cooldown_shoot, symbol, mir_symbol){
			this->cooldown_movement = cooldown_movement;
			lastmove_time = 0.0;
}

void MediumEnemy::movement(int player_x, int player_y, double time, bool hasPlatformBelow){
	if(time - lastmove_time > cooldown_movement){
		if(hasPlatformBelow){
			if(x < player_x){
				x++;
			}else if(x > player_x){
				x--;
			}
		}
		lastmove_time = time;
	}
}

						