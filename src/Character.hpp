#include <cmath>

#pragma once

#define KEY_DOWN	0402		/* down-arrow key */
#define KEY_UP		0403		/* up-arrow key */
#define KEY_LEFT	0404		/* left-arrow key */
#define KEY_RIGHT	0405		/* right-arrow key */

enum Direction {LEFT, RIGHT};

struct shot_struct{
	int x, y;
	Direction direction;
	shot_struct *next;
};
typedef shot_struct *p_shot;

class Character {
protected:
	const double FLIGHT_TIME = 0.3, COOLDOWN_JUMP = 0.4;
	int x, y, life, points, attack;
	double cooldown_movement, cooldown_shoot, lastmove_time, lastshot_time, lastjump_time;
	bool jumping;
	Direction direction;
	char *symbol;
	p_shot shots;
public:
	Character(int x, int y, int points, int life, int attack, double cooldown_shoot, double cooldown_movement, char *symbol);
	void decreaseLife(int damage);
	void shoots(double time);
	void move(int input, int width, int height, double time, bool hasPlatformAbove=false, bool hasPlatformAboveOne=false, bool hasPlatformBelow=true, bool hasPlatformBelowOne=false, bool hasPlatformRight=false, bool hasPlatformLeft=false);
	void updateShot(p_shot shot, int width);
	void deleteShot(p_shot shot);
	p_shot getShotHead();
	int getX();
	int getY();
	int getLife();
	int getPoints();
	int getAttack();
	Direction getDirection();
	bool isJumping();
	char *getSymbol();
};