#include "Character.hpp"

class EasyEnemy : public Character{
private:
    double last_attack;
public:
    EasyEnemy(int x, int y, int points=10, int life=5, int attack=5, double cooldown_shoot = 0.2, char *symbol=(char *)"<--", char *mir_symbol=(char *)"-->");
    void rocket(double time, int width, int height, int player_y);
};
