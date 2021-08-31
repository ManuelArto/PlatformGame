#include "Player.hpp"

Player::Player(int x, int y, int points, int life, int attack, double cooldown_shoot, char *symbol)
				:Character(x, y, points, life, attack, cooldown_shoot, cooldown_movement=-1, symbol) {
	name = new char[MAX_NAME_LENGTH];
	offset = 0;
	isInvincible = false;
	invincibility_timer = 5.0;
	minigun_timer = 5.0;
	default_cooldown_shoot = cooldown_shoot;
}

void Player::move(int input, int width, int height, double time, bool hasPlatformAbove, bool hasPlatformBelow) {
	Character::move(input, width, height, time, hasPlatformAbove, hasPlatformBelow);
	if ((offset > 0 && x < FIXED_X) || x > FIXED_X) {
		offset += x-FIXED_X;
		x = FIXED_X;
	}
	if (offset < 0)
		offset = 0;
}

void Player::checkBonusesTimer(double time) {
	if (time - invincibilityActivation_time > invincibility_timer)
		isInvincible = false;
	if (time - minigunActivation_time > minigun_timer)
		cooldown_shoot = default_cooldown_shoot;
}

void Player::increaseLife(int bonus_life) {
	life += bonus_life;
}

void Player::increasePoints(int bonus_points) {
	points += bonus_points;
}

void Player::setCooldownShoot(double minigun_cooldown, double time) {
	this->cooldown_shoot = minigun_cooldown;
	minigunActivation_time = time;
}

void Player::setInvincibility(double time) {
	isInvincible = true;
	invincibilityActivation_time = time;
}

int Player::getMaxNameLenght() {
	return MAX_NAME_LENGTH;
}
double Player::getInvincibilityTimer(double time) {
	if (isInvincible)
		return invincibility_timer - (time - invincibilityActivation_time);
	else
		return 0.0;
}
double Player::getMinigunTimer(double time) {
	if (cooldown_shoot != default_cooldown_shoot)
		return minigun_timer - (time - minigunActivation_time);
	else
		return 0.0;
}
bool Player::hasInvincibility() {
	return isInvincible;
}
char *Player::getName() {
	return name;
}
int Player::getOffset() {
	return offset;
}
int Player::noOffsetX() {
	return x;
}
int Player::getX() {
	return offset+Character::getX();
}
int Player::getFixedX() {
	return FIXED_X;
}