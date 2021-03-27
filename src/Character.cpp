#include "Character.hpp"

Character::Character(int x, int y, int points, int life, int attack) {
    this->x = x;
    this->y = y;
	this->points = points;
	this->life = life;
	this->attack = attack;
}

void Character::decreaseLife(int damage) {
    this->life -= damage;
}

void Character::shoots() {

}

void Character::moveUp() {
	// check if can
}

void Character::moveDown() {
	// check if can
}

void Character::moveLeft() {
	// check if can
}

void Character::moveRight() {
	// check if can
}