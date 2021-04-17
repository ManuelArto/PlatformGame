#include "Character.hpp"
#include <curses.h>
class HardEnemy : public Character{
public:
    HardEnemy(int x, int y, int points=30, int life=30, int attack=30);
    char* symbol();
    void follower(int player_x, int player_y);
};