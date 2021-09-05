#include "Bonus.hpp"

Bonus::Bonus(int x, int y, int type_number, int bonus_life, int bonus_points, double minigun_cooldown, double minigun_timer, double invincibility_timer) {
    this->x = x;
    this->y = y;
	this->bonus_life = bonus_life;
	this->bonus_points = bonus_points;
	this->minigun_cooldown = minigun_cooldown;
	this->minigun_timer = minigun_timer;
	this->invincibility_timer = invincibility_timer;
	switch (type_number) {
		case 0:
			this->type = POINTS;
			break;
		case 1:
			this->type = LIFE;
			break;
		case 2:
			this->type = INVINCIBILITY;
			break;
		case 3:
			this->type = MINIGUN;
			break;
	}
}

char *Bonus::getSymbol() {
	char *symbol;
	switch (type) {
		case INVINCIBILITY:
			symbol = (char *)"I";
			break;
		case LIFE:
			symbol = (char *)"L";
			break;
		case POINTS:
			symbol = (char *)"P";
			break;
		case MINIGUN:
			symbol = (char *)"G";
			break;
	}
	return symbol;
}

bonus_type Bonus::getBonusType() {
	return type;
}

double Bonus::getMinigunCooldown() {
	return minigun_cooldown;
}

double Bonus::getMinigunTimer() {
	return minigun_timer;
}

double Bonus::getInvincibilityTimer() {
	return invincibility_timer;
}

int Bonus::getBonusLife() {
	return bonus_life;
}

int Bonus::getBonusPoints() {
	return bonus_points;
}

int Bonus::getX() {
	return x;
}

int Bonus::getY() {
	return y;
}
