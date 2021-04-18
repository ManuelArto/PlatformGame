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
	EasyEnemy *e;
	MediumEnemy *m;
	HardEnemy *h;
public:
	Controller(View *view, Generator *generator);
	void run();
};