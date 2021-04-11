#include "View.hpp"
#include "Player.hpp"
#include "EasyEnemy.hpp"
#include "MediumEnemy.hpp"
#include "HardEnemy.hpp"
#include "Bonus.hpp"
#include "Platform.hpp"

class Controller {
private:
	View *view;
	Player *player, *player2;
	double time;
	EasyEnemy *e;
	MediumEnemy *m;
	HardEnemy *h;
	Bonus *b;
	Platform *platform;
public:
	Controller(View *view);
	void run();
};