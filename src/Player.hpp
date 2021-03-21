#include "Character.hpp"

class Player: public Character {
private:
	int time;
public:
	Player(int x, int y);
};