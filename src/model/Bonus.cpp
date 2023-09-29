#include "Bonus.hpp"

Bonus::Bonus(int x, int y, int level, int type_number, int bonus_life, int bonus_points, double minigun_cooldown, double minigun_timer, double invincibility_timer) {
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
			this->bonus_points += (INCREMENT_POINTS * (level/2));
			break;
		case 1:
			this->type = LIFE;
			this->bonus_life += (INCREMENT_LIFE * (level/2));
			break;
		case 2:
			this->type = INVINCIBILITY;
			if (this->invincibility_timer + (INCREMENT_INVINCIBILITY_TIMER * (level/2)) < MAX_INVINCIBILITY_TIMER)
				this->invincibility_timer += INCREMENT_INVINCIBILITY_TIMER * (level/2);
			else
				this->invincibility_timer = MAX_INVINCIBILITY_TIMER;
			break;
		case 3:
			this->type = MINIGUN;
			if (this->minigun_timer + (INCREMENT_MINIGUN_TIMER * (level/2)) < MAX_MINIGUN_TIMER)
				this->minigun_timer += INCREMENT_MINIGUN_TIMER * (level/2);
			else
				this->minigun_timer = MAX_MINIGUN_TIMER;
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
