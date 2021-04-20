#include "Character.hpp"
class MediumEnemy : public Character{
private:
    double cooldown_movement, lastmove_time;
    int temp_x, temp_y;
public:
    MediumEnemy(int x, int y, int point=20, int life=20, int attack=20, double cooldown_shoot=0.5, double cooldown_movement=0.5, char *symbol=(char *)"M", char *mir_symbol=(char *)"M");
    void movement(int player_x, int player_y, double time, bool hasPlatformBelow);
};

    