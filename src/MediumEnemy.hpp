#include "Character.hpp"

class MediumEnemy : public Character{
public:
    MediumEnemy(int x, int y, int point=20, int life=20, int attack=20, double cooldown=0.5, char *symbol=(char *)"M", char *mir_symbol=(char *)"M");
};