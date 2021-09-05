#include "View.hpp"
#include "Player.hpp"
#include "Generator.hpp"
#include "Collisions.hpp"

class Controller {
private:
	View *view;
	Generator *generator;
	Player *player;
	Collisions *collisions;
	double time;
	int room, level;
	void printShoots(Character *c, int offset);
	void manageEnemies();
	void checkRoomsGeneration();
	void checkCollisions();
	void checkBonusType(Bonus *bonus);
	void init();
	void initGeneration();
public:
	Controller(View *view, Generator *generator);
	void run();
};