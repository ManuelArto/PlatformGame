#include "EasyEnemy.hpp"

EasyEnemy::EasyEnemy(int x, int y, int points, int life, int attack, double cooldown_shoot, char *symbol, char *mir_symbol):Character(x, y, points, life, attack, cooldown_shoot=-1, symbol, mir_symbol){
    this->cooldown = cooldown;
    last_move = 0.0;
}

void EasyEnemy::rocket(double time){
    if(time - last_move > cooldown && x>0){
        x--;
        last_move = time;
    }
    if(x==0){

    }
}
