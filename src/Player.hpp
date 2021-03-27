#include "Character.hpp"

class Player: public Character {
private:
	int time;
public:
	Player(int x, int y, int points=0, int life=100, int attack=50);
};