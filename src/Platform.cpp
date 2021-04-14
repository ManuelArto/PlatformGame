#include "Platform.hpp"

Platform::Platform(){
    plat = __null;
}

p_plat Platform::create_platform(int x, int y, int length, p_plat plat){     //inserimento in testa delle piattaforme
    p_plat c = new platform;
    c -> x = x;
    c -> y = y;
    c -> length = length;
    c -> next = plat;
    plat = c;
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


