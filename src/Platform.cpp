#include "Platform.hpp"

Platform::Platform(){
    plat = __null;
}

void Platform::create_platform(int x, int y, int length){
    p_plat p = new platform;
    p -> x = x;
    p -> y = y;
    p -> lenght = length;
    p -> next = __null;

    if(plat == __null){
        plat = p;
    }else{
        p_plat iter = plat;
        while(iter->next != __null){
            iter = iter -> next;
        }
        iter -> next = p;
    }
    view->drawPlatform(x, y, length);
}

bool Platform::checkPlatform(int player_x, int player_y){
    bool flag = false;
    if(plat == __null){
        flag = false;
    }else{
        while(flag == false || plat != __null){
            if(player_x== plat->x && player_y == (plat->y)-1){
                flag = true;
            }else{
                plat = plat -> next;
            }
        }
    }
    return flag;
}


