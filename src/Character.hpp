#define KEY_DOWN	0402		/* down-arrow key */
#define KEY_UP		0403		/* up-arrow key */
#define KEY_LEFT	0404		/* left-arrow key */
#define KEY_RIGHT	0405		/* right-arrow key */

struct shot_struct{
	int x, y;
	shot_struct *next;
};
typedef shot_struct *p_shot;

class Character {
	private:
		int x, y, life, points, attack, n_shots;
		const double COOLDOWN = 0.5;
		double lastshot_time;
		p_shot shots, current_shot;
	public:
		Character(int x, int y, int points, int life, int attack);
		void decreaseLife(int damage);
		void shoots(double time);
		void move(int input, int width, int height);
		void updateShot(p_shot shot, int width);
		void deleteShot(p_shot shot);
		p_shot getShot(int index);
		int getX();
		int getY();
		int getLife();
		int getPoints();
		int getAttack();
		int getNShots();
};