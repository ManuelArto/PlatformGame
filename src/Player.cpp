#include "Player.hpp"
using namespace std;

Player::Player(int x, int y, int points, int life, int attack, double cooldown_shoot, char *symbol, char *mir_symbol)
				:Character(x, y, points, life, attack, cooldown_shoot, symbol, mir_symbol) {
	name = new char[MAX_NAME_LENGTH];
	isInvincible = false;
	invincibility_duration = 5.0;
	minigun_duration = 5.0;
	default_cooldown_shoot = cooldown_shoot;
}

void Player::checkBonusesDuration(double time) {
	if (time - invincibilityActivation_time > invincibility_duration)
		isInvincible = false;
	if (time - minigunActivation_time > minigun_duration)
		cooldown_shoot = default_cooldown_shoot;
}

void Player::increaseLife(int bonus_life) {
	life += bonus_life;
}

void Player::setCooldownShoot(double minigun_cooldown, double time) {
	this->cooldown_shoot = minigun_cooldown;
	minigunActivation_time = time;
}

void Player::setInvincibility(double time) {
	isInvincible = true;
	invincibilityActivation_time = time;
}

bool Player::hasInvincibility() {
	return isInvincible;
}

char *Player::getName() {
	return name;
}