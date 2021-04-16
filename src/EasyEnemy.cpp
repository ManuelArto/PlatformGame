#include "EasyEnemy.hpp"

EasyEnemy::EasyEnemy(int x, int y, int points, int life, int attack):Character(x, y, points, life, attack){}

char* EasyEnemy::symbol(){
    return "<--";
}


