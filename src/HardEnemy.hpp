#include "Character.hpp"

class HardEnemy : public Character{
private:
	static const int DECREMENT_COOLDOWN_MOVEMENT = 0.1, MIN_COOLDOWN_MOVEMENT = 0.2, INCREMENT_POINTS = 25, INCREMENT_ATTACK = 5, INCREMENT_LIFE = 5;
	bool findPlatform;
	int movement, last_movement;
	double min_distance_shoot;
public:
    HardEnemy(int x, int y, int level, int points=150, int life=60, int attack=30, double cooldown_shoot=0.5, double cooldown_movement=0.5, double min_distance_shoot=30, char *symbol=(char *)"H");
    void follow(int player_x, int player_y, double time, bool hasPlatformAbove, bool hasPlatformAboveOne, bool hasPlatformBelow, bool hasPlatformBelowOne, bool hasPlatformRight, bool hasPlatformLeft, int width, int height);
	// OVERLOAD
	void shoots(double time, int player_x);
};