#include "Character.hpp"

class Player: public Character {
private:
	const int MAX_NAME_LENGTH = 10;
	char *name;
public:
	Player(int x, int y, int points=0, int life=100, int attack=10, double cooldown=0.5, char *symbol=(char *)"S", char *mir_symbol=(char *)"Ƨ");
	char* getName();
};