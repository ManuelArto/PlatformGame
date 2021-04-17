#include "HardEnemy.hpp"

HardEnemy::HardEnemy(int x, int y, int points, int life, int attack):Character(x, y, points, life, attack){}

char* HardEnemy::symbol(){
    return "H";
}

void HardEnemy::follower(int player_x, int player_y){
    if(player_x < x){
        x--;
    }else if(player_x > x){
        x++;
    }
    if(player_y < y){
        y--;
    }else if(player_y > y){
        y++;
    }
}
