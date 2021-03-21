class Character {
private:
	int x, y, life, points, damage;
public:
	Character(int x, int y, int points=0, int life=100, int damage=50);
	void decreaseLife(int damage);
	void shoots();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
};