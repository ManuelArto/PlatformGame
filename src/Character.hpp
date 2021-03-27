class Character {
	private:
		int x, y, life, points, attack;
	public:
		Character(int x, int y, int points, int life, int attack);
		void decreaseLife(int damage);
		void shoots();
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
};