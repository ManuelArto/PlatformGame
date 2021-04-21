enum bonus_type {INVINCIBILITY, LIFE, POINTS, MINIGUN};

class Bonus {
private:
	int x, y;
	int bonus_life, bonus_points;
	double minigun_cooldown;
	bonus_type type;
public:
	Bonus(int x, int y, bonus_type type, int bonus_life=50, int bonus_points=50, double minigun_cooldown=0.2);
	bonus_type getBonusType();
	char *getSymbol();
	double getMinigunCooldown();
	int getBonusLife();
	int getBonusPoints();
	int getX();
	int getY();
};