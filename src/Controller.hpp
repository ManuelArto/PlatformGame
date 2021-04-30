#include "View.hpp"
#include "Player.hpp"
#include "Generator.hpp"
#include "EasyEnemy.hpp"
#include "MediumEnemy.hpp"
#include "HardEnemy.hpp"

class Controller {
private:
	View *view;
	Player *player;
	Generator *generator;
	double time, lastphysicdamage_time;
	const double PHYSIC_DAMAGE_COOLDOWN = 2.0;
	EasyEnemy *e;
	MediumEnemy *m;
	HardEnemy *h;
	void checkCollisions(Character *c);
	void printShoots(Character *c);
public:
	Controller(View *view, Generator *generator);
	void run();
};