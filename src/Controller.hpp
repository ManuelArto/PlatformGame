#include "View.hpp"
#include "Player.hpp"
#include "Generator.hpp"
#include "Collisions.hpp"
#include "EasyEnemy.hpp"
#include "MediumEnemy.hpp"
#include "HardEnemy.hpp"

class Controller {
private:
	View *view;
	Player *player;
	Generator *generator;
	Collisions *collisions;
	double time;
	int room;
	MediumEnemy *m;
	HardEnemy *h;
	EasyEnemy *e;
	void initSetup();
	void initGeneration();
	void checkRoomsGeneration();
	void checkCollisions();
	void checkBonusType(Bonus *bonus);
	void printShoots(Character *c, int offset);
public:
	Controller(View *view, Generator *generator);
	void run();
};