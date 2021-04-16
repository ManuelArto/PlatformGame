#include "Character.hpp"
#include <iostream>

class EasyEnemy : public Character{
public:
    EasyEnemy(int x=46, int y=rand()%18, int points=10, int life=5, int attack=5);
    char* symbol();
};
