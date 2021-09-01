#include "Collisions.hpp"

Collisions::Collisions(Player *player) {
	this->player = player;
}

bool Collisions::checkPhysicalDamage(Character *enemy) {
	return (player->getX() == enemy->getX()) && (player->getY() == enemy->getY());
}

bool Collisions::checkEnemyShootsDamage(Character *enemy) {
	return this->checkShootsDamage(enemy, player, player->getX());
}

bool Collisions::checkPlayerShootsDamage(Character *enemy) {
	return this->checkShootsDamage(player, enemy, enemy->getX());
}

// PRIVATE
bool Collisions::checkShootsDamage(Character *shooter, Character *character, int character_x) {
	bool hit = false;
	p_shot shot = shooter->getShotHead();
	while (shot != __null && !hit) {
		if (shot->y == character->getY()) {
			switch (shot->direction) {
				case LEFT:
					if (shot->x == character_x || shot->x == character_x-1)
						hit = true;
					break;
				case RIGHT:
					if (shot->x == character_x-2 || shot->x == character_x-1)
						hit = true;
					break;
				}
		}
		if (hit)
			shooter->deleteShot(shot);
		else
			shot = shot->next;
	}
	return hit;
}

void Collisions::checkShootsPlatformsCollision(Character *character, Platform *platforms[], int numberPlatforms) {
	p_shot tmp_shot, shot = character->getShotHead();
	while (shot != __null) {
		tmp_shot = shot->next;
		for (int i = 0; i < numberPlatforms; i++) {
			if (shot->y == platforms[i]->getY()) {
				switch (shot->direction) {
				case LEFT:
					if (shot->x >= platforms[i]->getX() && shot->x <= platforms[i]->getX()+platforms[i]->getLenght())
						character->deleteShot(shot);
					break;
				case RIGHT:
					if (shot->x+3 >= platforms[i]->getX() && shot->x+3 <= platforms[i]->getX()+platforms[i]->getLenght())
						character->deleteShot(shot);
					break;
				}
			}
		}
		shot = tmp_shot;
	}
}

bool Collisions::checkEasyEnemyCollision(EasyEnemy *enemy, Platform *platforms[], int numberPlatforms) {
	bool hit = false;
	int i = 0;
	if (enemy->getX() == 0)		// Collision with WALL
		hit = true;
	while (i < numberPlatforms && !hit) {
		if (enemy->getY() == platforms[i]->getY()) {
			if (enemy->getX() == platforms[i]->getX()-1 || enemy->getX() == (platforms[i]->getX()+platforms[i]->getLenght()+1))
				hit = true;
		}
		i++;
	}
	return hit;
}

// bool checkShootsCollision(p_shot shot) {}

bool Collisions::checkBonusColission(Bonus *bonus) {
	return (player->getX() == bonus->getX()) && (player->getY() == bonus->getY());
}
