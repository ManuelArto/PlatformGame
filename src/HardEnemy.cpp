#include "HardEnemy.hpp"

HardEnemy::HardEnemy(int x, int y, int points, int life, int attack):Character(x, y, points, life, attack){}

char* HardEnemy::symbol(){
    return "H";
}

void HardEnemy::follow(int player_x, int player_y, double time, p_plat p){
    bool flag;
    //controllo se il personaggio si trova su una piattaforma
    if(platform -> checkPlatformDown(x-1,y,p) || platform -> checkPlatformDown(x+1,y,p)){
        flag = true;
    }else{
        flag = false;
    }

    if(time - lastshot_time > 0.1){
        if(player_x < x){
            if((platform->checkPlatformDown(x,y,p) == false) && flag == true){
                y += 2;
                x--;
            }else{
                x--;
            }
        }else if(player_x > x){
           if((platform->checkPlatformDown(x,y,p) == false) && flag == true){
                y += 2;
                x++;
            }else{
                x++;
            }
        }else{
            if(player_y != y && flag == true){
                while(platform->checkPlatformDown(x,y,p)){
                    if(x <= p->length/2){
                        x--;
                    }else{
                        x++;
                    }
                    Sleep(100);
                }
            }
        }
        if(player_y < y){
            if(platform->checkPlatformUp(x,y,p)){
                y -= 2;
            }
        }else if(player_y > y){
            if(platform->checkPlatformDown(x,y,p) == false){
                y += 2;
            }
        }
        lastshot_time = time;
    }
}