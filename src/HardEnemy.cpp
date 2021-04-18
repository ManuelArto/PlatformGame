#include "HardEnemy.hpp"

HardEnemy::HardEnemy(int x, int y, int points, int life, int attack, double cooldown, char *symbol, char *mir_symbol):Character(x, y, points, life, attack, cooldown, symbol, mir_symbol){}

void HardEnemy::follow(int player_x, int player_y, double time, bool platformUp, bool platformDown, int width, int height) {
    if(time - last_move > 0.3){
        if(x < player_x){
            move(0405, width, height, platformUp, platformDown);
        }else{
            move(0404, width, height, platformUp, platformDown);
        }
        if(y < player_y){
            move(0402, width, height, platformUp, platformDown);
        }else if(y > player_y){
            move(0403, width, height, platformUp, platformDown);
        }
        last_move = time;
    }
}
