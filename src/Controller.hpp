#include "View.hpp"
#include "Player.hpp"
class Controller {
private:
	View *view;
	Player *player, *player2;
	double time;
public:
	Controller();
	void run();
};