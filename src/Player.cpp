#include "Player.hpp"
using namespace std;

Player::Player(int x, int y, int points, int life, int attack, double cooldown):Character(x, y, points, life, attack, cooldown) {
	name = new char[MAX_NAME_LENGTH];
}

char *Player::getName() {
	return name;
}