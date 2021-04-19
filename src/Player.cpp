#include "Player.hpp"
using namespace std;

Player::Player(int x, int y, int points, int life, int attack, double cooldown, double cooldown_jump, char *symbol, char *mir_symbol)
				:Character(x, y, points, life, attack, cooldown, cooldown_jump, symbol, mir_symbol) {
	name = new char[MAX_NAME_LENGTH];
}

char *Player::getName() {
	return name;
}