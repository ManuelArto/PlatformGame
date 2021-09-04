#include "View.hpp"
#include "Player.hpp"
#include "Generator.hpp"
#include "Collisions.hpp"

class Controller {
private:
	View *view;
	Player *player;
	Generator *generator;
	Collisions *collisions;
	double time;
	int room;
	void printShoots(Character *c, int offset);
	void manageEnemies();
	void checkRoomsGeneration();
	void checkCollisions();
	void checkBonusType(Bonus *bonus);
	void initSetup();
	void initGeneration();
public:
	Controller(View *view, Generator *generator);
	void run();
};