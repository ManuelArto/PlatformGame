#include "View.hpp"
#include "Player.hpp"
#include "EasyEnemy.hpp"
#include "MediumEnemy.hpp"
#include "HardEnemy.hpp"

class Controller {
private:
	View *view;
	Player *player, *player2;
	double time;
	EasyEnemy *e;
	MediumEnemy *m;
	HardEnemy *h;

public:
	Controller(View *view);
	void run();
};