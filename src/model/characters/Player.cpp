#include "Player.hpp"

Player::Player(int x, int y, int points, int life, int attack, double cooldown_shoot, char *symbol)
				:Character(x, y, points, life, attack, cooldown_shoot, cooldown_movement=-1, symbol) {
	name = new char[MAX_NAME_LENGTH];
	offset = 0;
	isInvincible = false;
	default_cooldown_shoot = cooldown_shoot;
}

void Player::move(int input, int width, int height, double time, bool hasPlatformAbove, bool hasPlatformAboveOne, bool hasPlatformBelow, bool hasPlatformBelowOne, bool hasPlatformRight, bool hasPlatformLeft) {
	Character::move(input, width, height, time, hasPlatformAbove, hasPlatformAboveOne, hasPlatformBelow, hasPlatformBelowOne, hasPlatformRight, hasPlatformLeft);
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

void Player::setCooldownShoot(double minigun_cooldown, double time, double timer) {
	this->cooldown_shoot = minigun_cooldown;
	minigun_timer = timer;
	minigunActivation_time = time;
}

void Player::setInvincibility(double time, double timer) {
	isInvincible = true;
	invincibility_timer = timer;
	invincibilityActivation_time = time;
}

void Player::setLastDamageTime(double time) {
	lastdamage_time = time;
}

// GETTER

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
bool Player::isDamaged(double time) {
	return (time - lastdamage_time <= COOLDOWN_DAMAGE);
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
// OVERRIDE
int Player::getX() {
	return offset+Character::getX();
}
int Player::getFixedX() {
	return FIXED_X;
}