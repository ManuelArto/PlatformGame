#include "Platform.hpp"

Platform::Platform(){
    plat = __null;
}

p_plat Platform::create_platform(int x, int y, int length, p_plat plat){     //inserimento in coda delle piattaforme
    if(plat == __null){
        plat -> x = x;
        plat -> y = y;
        plat -> length = length;
        plat -> next = __null;
    }else{
        p_plat iter = plat;
        while(iter->next != __null){
            iter = iter -> next;
        }
        iter -> next = new platform;
        iter = iter -> next;
        iter -> x = x;
        iter -> y = y;
        iter -> length = length;
        iter -> next = __null;
    }
    return plat;
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


