#include "Player.hpp"
#include <iostream>
using namespace std;

Player::Player(int x, int y, int points, int life, int attack):Character(x, y, points, life, attack){}


char* Player::getName(){
	char* name;
	cout << "Inserire nome utente: ";
	cin >> name;
	return name;
}