#include "Character.hpp"

class HardEnemy : public Character{
public:
    HardEnemy(int x, int y, int points=30, int life=30, int attack=30);
};