#include "Character.hpp"
#include "Platform.hpp"
#include <windows.h>

class HardEnemy : public Character{
private:
    Platform *platform;
public:
    HardEnemy(int x, int y, int points=30, int life=30, int attack=30);
    char* symbol();
    void follow(int player_x, int player_y, double time, p_plat p);
};