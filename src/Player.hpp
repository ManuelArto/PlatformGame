#include "Character.hpp"

class Player: public Character {
private:
	const int MAX_NAME_LENGTH = 10, FIXED_X = 15;
	int offset;
	double default_cooldown_shoot;
	double invincibility_timer, invincibilityActivation_time, minigun_timer, minigunActivation_time;
	bool isInvincible;
	char *name;
public:
	Player(int x, int y, int points=0, int life=100, int attack=10, double cooldown_shoot=0.5, char *symbol=(char *)"S", char *mir_symbol=(char *)"Ƨ");
	void increaseLife(int bonus_life);
	void increasePoints(int bonus_points);
	void checkBonusesTimer(double time);
	void setCooldownShoot(double cooldown_shoot, double time);
	void setInvincibility(double time);
	double getInvincibilityTimer(double time);
	double getMinigunTimer(double time);
	bool hasInvincibility();
	char* getName();
	int getOffset();
	int noOffsetX();
	// OVERRIDE
	void move(int input, int width, int height, bool hasPlatformAbove, bool hasPlatformBelow, double time);
	int getX();
};