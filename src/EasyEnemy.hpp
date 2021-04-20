#include "Character.hpp"

class EasyEnemy : public Character{
private:
    double cooldown, last_move;
public:
    EasyEnemy(int x, int y, int points=10, int life=5, int attack=5, double cooldown_shoot = 0.5, char *symbol=(char *)"<--", char *mir_symbol=(char *)"-->");
    void rocket(double time);
};
