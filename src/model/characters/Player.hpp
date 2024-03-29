#pragma once

#include "Character.hpp"

class Player: public Character {
private:
	const int MAX_NAME_LENGTH = 10, FIXED_X = 20, COOLDOWN_DAMAGE = 1.0;
	int offset;
	double default_cooldown_shoot, lastdamage_time;
	double invincibility_timer, invincibilityActivation_time, minigun_timer, minigunActivation_time;
	bool isInvincible;
	char *name;
public:
	Player(int x, int y, int points=0, int life=200, int attack=20, double cooldown_shoot=0.3, char *symbol=(char *)"S");
	void increaseLife(int bonus_life);
	void increasePoints(int bonus_points);
	void checkBonusesTimer(double time);
	void setCooldownShoot(double cooldown_shoot, double time, double timer);
	void setInvincibility(double time, double timer);
	void setInvincibilityTimer(double time);
	void setMinigunTimer(double time);
	void setLastDamageTime(double time);
	int getMaxNameLenght();
	double getInvincibilityTimer(double time);
	double getMinigunTimer(double time);
	bool isDamaged(double time);
	bool hasInvincibility();
	char* getName();
	int getOffset();
	int noOffsetX();
	int getFixedX();
	// OVERRIDE
	void move(int input, int width, int height, double time, bool hasPlatformAbove, bool hasPlatformAboveOne, bool hasPlatformBelow, bool hasPlatformBelowOne, bool hasPlatformRight, bool hasPlatformLeft);
	int getX();
};