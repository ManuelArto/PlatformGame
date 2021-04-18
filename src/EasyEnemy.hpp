#include "Character.hpp"

class EasyEnemy : public Character{
public:
    EasyEnemy(int x=46, int y=18, int points=10, int life=5, int attack=5, char *symbol=(char *)"-->", char *mir_symbol=(char *)"<--");
};
