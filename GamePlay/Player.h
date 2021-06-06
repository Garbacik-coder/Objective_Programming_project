#ifndef GAMETEMPLATE_PLAYER_H
#define GAMETEMPLATE_PLAYER_H


class Player {
    float height;
    float speed;
    float time; //określa jak długo gracz przytrzymuje przycisk, jest wykorzystywane do obliczenia prędkości
public:
    Player();

    float getHeight() { return height; };

    void changeTime(float t) { time += t; };

    void resetTime() { time = 0; };

    void move();

    void changeSpeed();

    float getSpeed() { return speed; };
};


#endif //GAMETEMPLATE_PLAYER_H
