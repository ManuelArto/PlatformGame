#include "EasyEnemy.hpp"

EasyEnemy::EasyEnemy(int x, int y, int points, int life, int attack, char *symbol):Character(x, y, points, life, attack, cooldown_shoot=-1, symbol){
    last_attack = 0.0;
}

// da modificare
void EasyEnemy::rocket(double time, int width, int height, int player_y){
    bool flag = false;
        if(x == -2){
            flag = true;
        }else{
            x--;
        }
            
        if(time - last_attack > cooldown_shoot && flag){
            x = width;
            y = player_y;
            last_attack = time;
        }
}