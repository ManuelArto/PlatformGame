#include "View.hpp"

struct platform{
    int x, y, lenght;
    platform *next;
};
typedef platform *p_plat;

class Platform{
    private:
        p_plat plat;
        View *view;
    public:
        Platform();
        void create_platform(int x, int y, int length);
        bool checkPlatform(int player_x, int player_y);
};