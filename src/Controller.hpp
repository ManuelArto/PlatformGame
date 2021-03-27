#include "Screen.hpp"
#include "Player.hpp"
class Controller {
private:
	Screen *screen;
	Player *player;
public:
	Controller();
	void init();
};