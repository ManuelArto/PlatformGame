#include "Character.hpp"

Character::Character(int x, int y, int points, int life, int attack) {
    this->x = x;
    this->y = y;
	this->points = points;
	this->life = life;
	this->attack = attack;
	n_shots = 0;
	shots = __null;
}

void Character::decreaseLife(int damage) {
    this->life -= damage;
}

void Character::shoots() {
	p_shot shot = new shot_struct;
	shot->x = x+1; shot->y = y;
	shot->next = __null;
	if (shots == __null) {
		shots = shot;
		current_shot = shots;
	} else {
		p_shot iter = shots;
		while(iter->next != __null)
			iter = iter->next;
		iter->next = shot;
	}
	n_shots++;
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
			n_shots--;
		} else {
			prev = iter;
			iter = iter->next;
		}
	}
}

p_shot Character::getShot(int index) {
	p_shot shot = current_shot;
	if (index == n_shots-1)
		current_shot = shots;
	else
		current_shot = current_shot->next;
	return shot;
}

// TODO: bug multi sparo segmentation fault con current_shot
void Character::updateShot(p_shot shot, int width) {
	if (current_shot->x < width-3)
		current_shot->x++;
	else
		deleteShot(current_shot);
}

void Character::move(int input, int width, int height) {
	switch (input){
		case KEY_UP:
			if (y > 0)
				y--;
			break;
		case KEY_DOWN:
			if (y < height-1)
				y++;
			break;
		case KEY_LEFT:
			if (x > 0)
				x--;
			break;
		case KEY_RIGHT:
			if (x < width-1)
				x++;
			break;
	}
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

int Character::getNShots() {
	return n_shots;
}