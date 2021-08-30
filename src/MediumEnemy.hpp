#include "Character.hpp"
class MediumEnemy : public Character{
private:
    double cooldown_movement, lastmove_time;
    int direction;
public:
    MediumEnemy(int x, int y, int point=20, int life=20, int attack=20, double cooldown_shoot=0.5, double cooldown_movement=0.5, char *symbol=(char *)"M");
    void follow(int player_x, int player_y, double time, bool hasPlatformAbove, bool hasPlatformBelow, int width, int height, bool hasPlatformRight, bool hasPlatformLeft);
};

    
