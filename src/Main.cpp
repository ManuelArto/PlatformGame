#include "Controller.hpp"

int main() {
	View *view = new View();
	Controller *controller = new Controller(view);
	controller->run();

	return 0;
}