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
	bool checkEasyEnemyPhysicalDamage(Character *enemy);
	bool checkEnemyShoots(Character *enemy);
	bool checkPlayerShoots(Character *enemy);
	void checkShootsPlatformsCollision(Character *character, Platform *platforms[], int numberPlatforms);
	bool checkEasyEnemyCollision(EasyEnemy *enemy, Platform *platforms[], int numberPlatforms);
	void checkShootsCollision(Character *enemy);
	bool checkBonusColission(Bonus *bonus);
};