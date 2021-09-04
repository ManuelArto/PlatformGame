#include "Character.hpp"
class MediumEnemy : public Character {
private:
	double min_distance_shoot;
public:
    MediumEnemy(int x, int y, int point=20, int life=20, int attack=20, double cooldown_shoot=0.5, double cooldown_movement=0, double min_distance_shoot=30, char *symbol=(char *)"M");
    void follow(int player_x, double time, int width, int height, bool hasPlatformBelowRight, bool hasPlatformBelowLeft, bool hasPlatformRight, bool hasPlatformLeft);
	// OVERLOAD
	void shoots(double time, int player_x, int player_y);
};