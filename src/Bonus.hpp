#pragma once

enum bonus_type {INVINCIBILITY, LIFE, POINTS, MINIGUN};

class Bonus {
private:
	int x, y;
	int bonus_life, bonus_points;
	double minigun_cooldown, minigun_timer, invincibility_timer;
	bonus_type type;
public:
	Bonus(int x, int y, int type_number, int bonus_life=30, int bonus_points=50, double minigun_cooldown=0.2, double minigun_timer=5.0, double invincibility_timer=5.0);
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