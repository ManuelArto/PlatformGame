#include "EasyEnemy.hpp"

EasyEnemy::EasyEnemy(int x, int y, int points, int life, int attack, char *symbol, char *mir_symbol):Character(x, y, points, life, attack, cooldown_shoot=-1, symbol, mir_symbol){}

