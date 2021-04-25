#include "Controller.hpp"

int main() {
	View *view = new View();
	Generator *generator = new Generator();
	Controller *controller = new Controller(view, generator);
	
	// LOOP
	controller->run();

	return 0;
}