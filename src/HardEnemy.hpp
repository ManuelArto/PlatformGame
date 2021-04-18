#include "Character.hpp"

class HardEnemy : public Character{
private:
public:
    HardEnemy(int x, int y, int points=30, int life=30, int attack=30, double cooldown=0.5, char *symbol=(char *)"H", char *mir_symbol=(char *)"H");
    void follow(int player_x, int player_y, double time, bool platformUp, bool platformDown);
};