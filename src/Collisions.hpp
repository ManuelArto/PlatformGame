#include <cmath>

#include "Player.hpp"
#include "EasyEnemy.hpp"
#include "Platform.hpp"
#include "Bonus.hpp"

class Collisions {
private:
	Player *player;
	bool checkShootsDamage(Character *shooter, Character *character, int character_x);
public:
	Collisions(Player *player);
	bool checkPhysicalDamage(Character *enemy);
	bool checkEnemyShootsDamage(Character *enemy);
	bool checkPlayerShootsDamage(Character *enemy);
	void checkShootsPlatformsCollision(Character* character, Platform *platforms[], int numberPlatforms);
	bool checkEasyEnemyCollision(EasyEnemy *enemy, Platform *platforms[], int numberPlatforms);
	// bool checkShootsCollision(p_shot shot);
	bool checkBonusColission(Bonus *bonus);
};