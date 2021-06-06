#include <iostream>
#include "Player.h"

Player::Player() {
    height = 0;
    time = 0;
    speed = 0;
}

void Player::changeSpeed() {
//    float g = 3;
//    speed = g * (time / (1 + time));
    if (time>0){
        speed=0.08;
    }
    if (time==0){
        speed=0;
    }
    if (time<0){
        speed=-0.08;
    }
}

void Player::move() {
    if (height >= 0 && height <= 20) {
        height += speed;
    }
    if (height < 0) {
        resetTime();
        height = 0;
    }
    if (height > 20) {
        resetTime();
        height = 20;
    }
}
