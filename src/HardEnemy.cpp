#include "HardEnemy.hpp"

HardEnemy::HardEnemy(int x, int y, int points, int life, int attack):Character(x, y, points, life, attack){}

char* HardEnemy::symbol(){
    return "H";
}

void HardEnemy::follower(int player_x, int player_y, double time, p_plat p){
    bool flag = false;
    if(time - lastshot_time > 0.05){
        if(player_x < x){
            if((platform->checkPlatformDown(x,y,p) == false) && flag == true){
                y += 2;
                x--;
                flag = false;
            }else{
                x--;
            }
        }else if(player_x > x){
           if((platform->checkPlatformDown(x,y,p) == false) && flag == true){
                y += 2;
                x++;
                flag = false;
            }else{
                x++;
            }
        }

        if(player_y < y){
            if(platform->checkPlatformUp(x,y,p)){
                y -= 2;
                flag = true;
            }
        }else if(player_y > y){
            if(platform->checkPlatformDown(x,y,p) == false){
                y += 2;
                flag = false;
            }
        }else if((player_y == y) && (player_x != x) && (flag == true)){
            if(platform->checkPlatformDown(x,y,p) == false){
                y += 2;
                flag = false;
            }
        }
        lastshot_time = time;
    }
}