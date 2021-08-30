#include "Controller.hpp"

Controller::Controller(View *view, Generator *generator) {
	this->view = view;
	this->generator = generator;
	time = 0.0;
	room = 1;
	player = new Player (0, view->getGameHeight()-1);
	h = new HardEnemy(view->getGameWidth()-1, view->getGameHeight()-1);
	m = new MediumEnemy(10, view->getGameHeight()-5);
	e = __null;
}

void Controller::run() {
	bool quit = false;
	this->initSetup();

	do {
		
		// DATA MANAGEMENT
		if(e == __null){
			e = new EasyEnemy(view->getGameWidth()-3, player->getY());
		}
		int input = view->getKeyboardInput();
		switch (input) {
			case 'q':
				quit = true;
				break;
			case 'e':
				player->shoots(time);
				break;
			case KEY_RESIZE:
				view->clearWindow();
				view->checkDimensions();
				break;
		}

		player->move(input, view->getGameWidth(), view->getGameHeight(), 
					Platform::checkPlatformAbove(generator->getPlatforms(), generator->getNumberPlatforms(), player->getX(), player->getY()), 
					Platform::checkPlatformBelow(generator->getPlatforms(), generator->getNumberPlatforms(), player->getX(), player->getY()),
					time);
		h->follow(player->getX(), player->getY(), time,
					Platform::checkPlatformAbove(generator->getPlatforms(), generator->getNumberPlatforms(), h->getX(), h->getY()), 
					Platform::checkPlatformBelow(generator->getPlatforms(), generator->getNumberPlatforms(), h->getX(), h->getY()),
					view->getGameWidth(), view->getGameHeight());
		h->shoots(time);

		m->shoots(time);

		m->follow(player->getX(), player->getY(), time,
					Platform::checkPlatformAbove(generator->getPlatforms(), generator->getNumberPlatforms(), m->getX(), m->getY()), 
					Platform::checkPlatformBelow(generator->getPlatforms(), generator->getNumberPlatforms(), m->getX(), m->getY()),
					view->getGameWidth(), view->getGameHeight(),
					Platform::checkPlatformBelow(generator->getPlatforms(), generator->getNumberPlatforms(), m->getX()+1, m->getY()),
					Platform::checkPlatformBelow(generator->getPlatforms(), generator->getNumberPlatforms(), m->getX()-1, m->getY()));
		
		e -> rocket(time, view->getGameWidth()-3, view->getGameHeight(), player->getY());

		// DRAW MAP
		view->clearWindow();
		view->drawBorders();
		view->printInfos(player->getName(), time, player->getLife(), player->getPoints(), room, player->getInvincibilityTimer(time), player->getMinigunTimer(time));

		// PRINT ENTITIES
		view->printObject(player->noOffsetX(), player->getY(), (char *)"%s", player->getSymbol(), 0, player->hasInvincibility());
		this->printShoots(player, 0);
		view->printObject(h->getX(), h->getY(), (char *)"%s", (char *) h->getSymbol(), player->getOffset());
		this->printShoots(h, player->getOffset());
		view->printObject(m->getX(), m->getY(), (char *)"%s", (char *) m->getSymbol(), player->getOffset());
		this->printShoots(m, player->getOffset());
		view->printObject(e->getX(), e->getY(), (char *)"%s", (char *) e->getSymbol(), player->getOffset());
		
		// CREATE AND PRINT PLATFORM
		for (int i = 0; i < generator->getNumberPlatforms(); i++) {
			Platform *platf = generator->getPlatform(i);
			view->printPlatform(platf->getX(), platf->getY(), platf->getLenght(), player->getOffset());
		}
		for (int i = 0; i < generator->getNumberBonuses(); i++) {
			Bonus *bonus = generator->getBonus(i);
			view->printObject(bonus->getX(), bonus->getY(), "%s", bonus->getSymbol(), player->getOffset());
		}

		// CHECKS
		player->checkBonusesTimer(time);
		this->checkRoomsGeneration();
		this->checkCollisions();

		view->update();
		time += (double)view->getDelay() / 1000;
	} while (!quit || player->getLife() > 0); // TODO: change || to &&

	view->printGameOver();
	view->exitWindow();
}


void Controller::printShoots(Character *c, int offset) {
	p_shot tmp_shot, shot;
	shot = c->getShotHead();
	while(shot != __null) {
		view->printObject(shot->x, shot->y, (char *)"%s", (char *)"---", offset);
		tmp_shot = shot->next;
		c->updateShot(shot, view->getGameWidth()+offset);
		shot = tmp_shot;
	}
}

void Controller::checkRoomsGeneration() {
	room = (player->getOffset() / view->getGameWidth()) + 1;
	if (room > generator->getCurrentRoom()) {
		generator->deleteRoom(room, LEFT_ROOM);
		generator->createRoom(room+1, RIGHT_ROOM, view->getGameWidth());
	} else if (room < generator->getCurrentRoom()) {
		generator->deleteRoom(room+1, RIGHT_ROOM);
		generator->createRoom(room, LEFT_ROOM, view->getGameWidth());
	}
}

/* TODO: Check every collisions
			- Contatto fisico: Player - Enemies
			- Player (piattaforme o spari) - Spari Enemies
			- Player spari - Enemies (piattaforme o spari)
			- Player - bonuses
*/
void Controller::checkCollisions() {
	// // player - HardEnemy
	// if(!player->hasInvincibility() && (player->getX() == h->getX() && player->getY() == h->getY()))
	// 	player->decreaseLife(h->getAttack());

	// bool hit = false;
	// // PHYSICAL COLLISION
	// if (time - lastphysicdamage_time > PHYSIC_DAMAGE_COOLDOWN) {
	// 	if((player->getX() == c->getX()) && (player->getY() == c->getY())){
	// 		player->decreaseLife(c->getAttack());
	// 		if(c == e){
	// 			delete(e);
	// 			e = __null;
	// 		}
	// 		lastphysicdamage_time = time;
	// 	}
	// }

	// // sparo contro giocatore
	// p_shot tmp_shot, shot;
	// shot = c->getShotHead();
	// while (shot != __null && !hit) {
	// 	if ((player->getX() == shot->x) && (player->getY() == shot->y)) {
	// 		player->decreaseLife(c->getAttack());
	// 		c -> deleteShot(shot);
	// 		hit = true;
	// 	} else {
	// 		tmp_shot = shot->next;
	// 		shot = tmp_shot;
	// 	}
	// }

	// // sparo contro nemici da sistemare, si ferma il programma
	// p_shot shot2 = player->getShotHead();
	// while(shot2 != nullptr){
	// 	if(c->getX() == shot2->x && c->getY() == shot2->y){
	// 		c->decreaseLife(player->getAttack());
	// 		player->deleteShot(shot2);
	// 	}else{
	// 		tmp_shot = shot2->next;
	// 		shot2 = tmp_shot;
	// 	}
	// }

	// if(c->getLife() == 0){
	// 	delete(c);
	// 	c = __null;
	// }

	// if(e != __null && e->getX() == 0){
	// 	delete(e);
	// 	e = __null;
	// }
	// player - Bonuses
	for (int i = 0; i < generator->getNumberBonuses(); i++) {
		Bonus *bonus = generator->getBonus(i);
		if (player->getX() == bonus->getX() && player->getY() == bonus->getY())
			this->checkBonusType(bonus);	// TODO: remove bonus from game
	}
}

void Controller::checkBonusType(Bonus *bonus) {
	switch (bonus->getBonusType()) {
		case INVINCIBILITY:
			player->setInvincibility(time);
			break;
		case LIFE:
			player->increaseLife(bonus->getBonusLife());
			break;
		case POINTS:
			player->increasePoints(bonus->getBonusPoints());
			break;
		case MINIGUN:
			player->setCooldownShoot(bonus->getMinigunCooldown(), time);
			break;
	}
}

void Controller::initSetup() {
	view->createWindow();
	view->checkDimensions();
	view->printLoadingGame();
	view->askName(player->getName(), player->getMaxNameLenght());
	this->initGeneration();
}

void Controller::initGeneration() {
	generator->createRoom(room, LEFT_ROOM, view->getGameWidth());
	generator->createRoom(room+1, RIGHT_ROOM, view->getGameWidth());
	generator->createBonuses();
}