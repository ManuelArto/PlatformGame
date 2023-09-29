#include <cmath>

#include "../model/characters/Player.hpp"
#include "../model/characters/EasyEnemy.hpp"
#include "../model/Platform.hpp"
#include "../model/Bonus.hpp"

class Collisions {
private:
	Player *player;
public:
	Collisions(Player *player);
	bool checkPhysicalDamage(Character *enemy);
	bool checkEasyEnemyPhysicalDamage(Character *enemy);
	bool checkShootsDamage(Character *shooter, Character *character);
	void checkShootsPlatformsCollision(Character *character, Platform *platforms[], int numberPlatforms);
	bool checkEasyEnemyCollision(EasyEnemy *enemy, Platform *platforms[], int numberPlatforms);
	void checkShootsCollision(Character *enemy);
	bool checkBonusColission(Bonus *bonus);
};