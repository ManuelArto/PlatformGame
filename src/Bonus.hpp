class Bonus{
    private:
        int b_points, b_life;
        const double b_cooldown = 0.2;
    public:
        Bonus(int points, int life);
        void bonus_life(int life);
        void bonus_points(int points);
        void bonus_shoot();
};