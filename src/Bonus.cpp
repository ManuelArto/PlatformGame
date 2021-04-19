#include "Bonus.hpp"

Bonus::Bonus(int x, int y, bonus_type type, int bonus_life, double minigun_cooldown) {
    this->x = x;
    this->y = y;
	this->type = type;
	this->bonus_life = bonus_life;
	this->minigun_cooldown = minigun_cooldown;
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
		case MINIGUN:
			symbol = (char *)"G";
			break;
		case RALLENTY:
			symbol = (char *)"R";
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

int Bonus::getBonusLife() {
	return bonus_life;
}

int Bonus::getX() {
	return x;
}

int Bonus::getY() {
	return y;
}
