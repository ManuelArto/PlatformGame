#include "Character.hpp"
class MediumEnemy : public Character{
public:
    MediumEnemy(int x, int y, int point=20, int life=20, int attack=20, double cooldown_shoot=0.5, double cooldown_movement=0, char *symbol=(char *)"M");
    void follow(int player_x, double time, int width, int height, bool hasPlatformRight, bool hasPlatformLeft);
};