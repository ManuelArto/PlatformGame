#include "Character.hpp"

class EasyEnemy : public Character{
private:
    double last_attack;
public:
    EasyEnemy(int x=46, int y=18, int points=10, int life=5, int attack=5, char *symbol=(char *)"<--");
    void rocket(double time, int width, int height, int player_y);
};
