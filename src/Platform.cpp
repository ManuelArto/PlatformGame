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

bool Platform::checkPlatformUp(int player_x, int player_y, p_plat plat){
    p_plat temp = plat;
    if(temp == __null){
        return false;
    }else{
        while(temp != __null){
            if((player_x >= (temp->x) && player_x <= (temp -> x + temp -> length)) && (player_y == (temp->y)+1)){
                return true;
            }else{
                temp = temp -> next;
            }
        }
    }
    return false;
}

bool Platform::checkPlatformDown(int player_x, int player_y, p_plat plat){
    p_plat temp = plat;
    if(temp == __null){
        return false;
    }else{
        while(temp != __null){
            if((player_x >= (temp->x) && player_x < (temp -> x + temp -> length)) && (player_y == (temp->y)-1)){
                return true;
            }else{
                temp = temp -> next;
            }
        }
    }
    return false;
}

