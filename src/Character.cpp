#include "Character.hpp"

Character::Character(int x, int y, int points, int life, int attack, double cooldown, char *symbol, char *mir_symbol) {
    this->x = x;
    this->y = y;
	this->points = points;
	this->life = life;
	this->attack = attack;
	this->cooldown = cooldown;
	this->symbol = symbol;
	this->mir_symbol = mir_symbol;
	direction = RIGHT;
	shots = __null;
}

void Character::decreaseLife(int damage) {
    this->life -= damage;
}

void Character::move(int input, int width, int height) {
	switch (input) {
		case KEY_UP:
			if (y >= 2)
				y -= 2;
			break;
		case KEY_DOWN:
			if (y < height-2)
				y += 2;
			break;
		case KEY_LEFT:
			if (x > 0)
				x--;
			direction = LEFT;
			break;
		case KEY_RIGHT:
			if (x < width-1)
				x++;
			direction = RIGHT;
			break;
	}
}

void Character::shoots(double time) {
	if (time - lastshot_time > cooldown) {
		p_shot shot = new shot_struct;
		shot->x = direction == LEFT ? x-3 : x+1; 
		shot->y = y;
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
	if (shot->x > x && shot->x < width-3){
		shot->x++;
	} else if (shot->x < x && shot->x > 0){
		shot->x--;
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
double Character::getCoolDown() {
	return cooldown;
}
char *Character::getSymbol() {
	return direction == RIGHT ? symbol : mir_symbol;
}