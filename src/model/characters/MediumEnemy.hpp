#include "Character.hpp"
class MediumEnemy : public Character {
private:
	static const int DECREMENT_COOLDOWN_MOVEMENT = 0.2, MIN_COOLDOWN_MOVEMENT = 0.4, INCREMENT_POINTS = 25, INCREMENT_ATTACK = 5, INCREMENT_LIFE = 5;
	double min_distance_shoot;
public:
    MediumEnemy(int x, int y, int level, int point=100, int life=40, int attack=20, double cooldown_shoot=1.0, double cooldown_movement=1.0, double min_distance_shoot=30, char *symbol=(char *)"M");
	void move(int player_x, double time, int width, int height, bool hasPlatformBelowRight, bool hasPlatformBelowLeft, bool hasPlatformRight, bool hasPlatformLeft);
	// OVERLOAD
	void shoots(double time, int player_x, int player_y);
};