#pragma once

enum bonus_type {INVINCIBILITY, LIFE, POINTS, MINIGUN};

class Bonus {
private:
	static const int INCREMENT_POINTS = 25, INCREMENT_LIFE = 20, INCREMENT_MINIGUN_TIMER = 1, MAX_MINIGUN_TIMER = 12, INCREMENT_INVINCIBILITY_TIMER = 1, MAX_INVINCIBILITY_TIMER = 12;
	int x, y;
	int bonus_life, bonus_points;
	double minigun_cooldown, minigun_timer, invincibility_timer;
	bonus_type type;
public:
	Bonus(int x, int y, int level, int type_number, int bonus_life=30, int bonus_points=50, double minigun_cooldown=0.2, double minigun_timer=5.0, double invincibility_timer=5.0);
	bonus_type getBonusType();
	char *getSymbol();
	double getMinigunCooldown();
	double getMinigunTimer();
	double getInvincibilityTimer();
	int getBonusLife();
	int getBonusPoints();
	int getX();
	int getY();
};