#include "Player.hpp"
using namespace std;

Player::Player(int x, int y, int points, int life, int attack, double cooldown_shoot, char *symbol, char *mir_symbol)
				:Character(x, y, points, life, attack, cooldown_shoot, symbol, mir_symbol) {
	name = new char[MAX_NAME_LENGTH];
}

char *Player::getName() {
	return name;
}