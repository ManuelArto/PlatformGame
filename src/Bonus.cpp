#include "Bonus.hpp"

Bonus::Bonus(int b_life, int b_points){
    this->b_life = b_life;
    this->b_points = b_points;
}

void Bonus::bonus_life(int life){
    life += this->b_life;
}

void Bonus::bonus_points(int points){
    points += this->b_points;
}

void bonus_shoot(){
    
}