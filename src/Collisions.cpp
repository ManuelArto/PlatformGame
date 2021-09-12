#include "Collisions.hpp"

Collisions::Collisions(Player *player) {
	this->player = player;
}

bool Collisions::checkPhysicalDamage(Character *enemy) {
	return (player->getX() == enemy->getX()) && (player->getY() == enemy->getY());
}

bool Collisions::checkEasyEnemyPhysicalDamage(Character *enemy) {
	bool sameY = (enemy->getY() == player->getY());
	return sameY && (enemy->getX() == player->getX() || enemy->getX() == player->getX()-1);
}
bool Collisions::checkShootsDamage(Character *shooter, Character *character) {
	bool hit = false;
	p_shot next_shot, shot = shooter->getShotHead();
	while (shot != NULL) {
		next_shot = shot->next;
		if (shot->y == character->getY()) {
			if (abs(character->getX() - shot->x) <= 2 && abs(character->getX() - shot->x) >= 0)
				hit = true;
		}
		if (hit)
			shooter->deleteShot(shot);
		shot = next_shot;
	}
	return hit;
}

void Collisions::checkShootsPlatformsCollision(Character *character, Platform *platforms[], int numberPlatforms) {
	p_shot next_shot, shot = character->getShotHead();
	while (shot != NULL) {
		next_shot = shot->next;
		for (int i = 0; i < numberPlatforms; i++) {
			if (platforms[i] != NULL) {
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
		}
		shot = next_shot;
	}
}

bool Collisions::checkEasyEnemyCollision(EasyEnemy *enemy, Platform *platforms[], int numberPlatforms) {
	bool hit = false;
	int i = 0;
	if (enemy->getX() == 0)		// Collision with WALL
		hit = true;
	while (i < numberPlatforms && !hit) {
		if (platforms[i] != NULL) {
			if (enemy->getY() == platforms[i]->getY()) {
				if (enemy->getX() >= platforms[i]->getX() && enemy->getX() <= platforms[i]->getX()+platforms[i]->getLenght())
					hit = true;
			}
		}
		i++;
	}
	return hit;
}

void Collisions::checkShootsCollision(Character *enemy) {
	p_shot next_shot_player, shot_player = player->getShotHead();
	while (shot_player != NULL) {
		next_shot_player = shot_player->next;
		p_shot next_shot_enemy, shot_enemy = enemy->getShotHead();
		while (shot_enemy != NULL) {
			next_shot_enemy = shot_enemy->next;
			if (shot_player->y == shot_enemy->y) {
				if (abs(shot_enemy->x - shot_player->x) <= 2 && abs(shot_enemy->x - shot_player->x) >= 0) {
					player->deleteShot(shot_player);
					enemy->deleteShot(shot_enemy);
				}
			}
			shot_enemy = next_shot_enemy;
		}
		shot_player = next_shot_player;
	}
}

bool Collisions::checkBonusColission(Bonus *bonus) {
	return (player->getX() == bonus->getX()) && (player->getY() == bonus->getY());
}
