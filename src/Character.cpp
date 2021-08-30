#include "Character.hpp"

Character::Character(int x, int y, int points, int life, int attack, double cooldown_shoot, char *symbol) {
    this->x = x;
    this->y = y;
	this->points = points;
	this->life = life;
	this->attack = attack;
	this->cooldown_shoot = cooldown_shoot;
	this->symbol = symbol;
	jumping = false;
	lastjump_time = 0.0;
	direction = RIGHT;
	shots = __null;
}

void Character::decreaseLife(int damage) {
    this->life -= damage;
}

void Character::move(int input, int width, int height, bool hasPlatformAbove, bool hasPlatformBelow, double time) {
	if (jumping && (time - lastjump_time > FLIGHT_TIME)) {
		y += 1;
		jumping = false;
	} else if (!jumping && !hasPlatformBelow && y < height-2)
		// FALLING
		y += 2;
	else {
		switch (input) {
			case KEY_UP:
				if (y >= 2 && hasPlatformAbove && (hasPlatformBelow || y == height-1))
					y -= 2;
				else if (!hasPlatformAbove && !jumping && (time - lastjump_time > COOLDOWN_JUMP)) {
					y -= 1;
					jumping = true;
					lastjump_time = time;
				}
				break;
			case KEY_LEFT:
				if (x > 0 && (direction == LEFT || jumping))
					x += (jumping && x > 1) ? -2 : -1;
				direction = LEFT;
				break;
			case KEY_RIGHT:
				if (direction == RIGHT || jumping)
					x += (jumping && x < width-2) ? 2 : 1;
				direction = RIGHT;
				break;
			case KEY_DOWN:
				if (y < height-2)
					y += 2;
				break;
		}
	}
}

void Character::shoots(double time) {
	if (time - lastshot_time > cooldown_shoot) {
		p_shot shot = new shot_struct;
		shot->x = direction == LEFT ? x-3 : x+1;
		shot->y = y;
		shot->direction = direction;
		shot->next = __null;
		if (shots == __null) {
			shots = shot;
		} else {
			p_shot iter = shots;
			while(iter->next != __null)
				iter = iter->next;
			iter->next = shot;
		}
		lastshot_time = time;
	}
}

void Character::deleteShot(p_shot shot) {
	p_shot prev = shots, iter = shots;
	bool found = false;
	while (!found) {
		if (iter == shot) {
			if (iter == shots) {
				shots = iter->next;
				delete iter;
			} else {
				prev->next = iter->next;
				delete iter;
			}
			found = true;
		} else {
			prev = iter;
			iter = iter->next;
		}
	}
}

void Character::updateShot(p_shot shot, int width) {
	if (shot->x > 0 && shot->x < width-3) {
		shot->x += shot->direction == LEFT ? -1 : 1;
	} else
		deleteShot(shot);
}

p_shot Character::getShotHead() {
	return shots;
}

int Character::getX() {
	return x;
}
int Character::getY() {
	return y;
}
int Character::getLife() {
	return life;
} 
int Character::getPoints() {
	return points;
} 
int Character::getAttack() {
	return attack;
}
Direction Character::getDirection() {
	return direction;
}
bool Character::isJumping() {
	return jumping;
}
char *Character::getSymbol() {
	return symbol;
}