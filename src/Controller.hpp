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
	double time;
	int room;
	EasyEnemy *e;
	MediumEnemy *m;
	HardEnemy *h;
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