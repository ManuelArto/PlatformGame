struct platform{
    int x, y, lenght;
    platform *next;
};
typedef platform *p;

class Platform{
    private:
        p plat;
    public:
        Platform();
        void create_platform();
};