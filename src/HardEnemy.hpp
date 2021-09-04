#include "Character.hpp"

class HardEnemy : public Character{
private:
	bool findPlatform;
	int movement, last_movement;
	double min_distance_shoot;
public:
    HardEnemy(int x, int y, int points=30, int life=30, int attack=30, double cooldown_shoot=1.2, double cooldown_movement=0, double min_distance_shoot=30, char *symbol=(char *)"H");
    void follow(int player_x, int player_y, double time, bool hasPlatformAbove, bool hasPlatformAboveOne, bool hasPlatformBelow, bool hasPlatformBelowOne, bool hasPlatformRight, bool hasPlatformLeft, int width, int height);
	// OVERLOAD
	void shoots(double time, int player_x);
};