#ifndef GAMETEMPLATE_GAMEPLAY_H
#define GAMETEMPLATE_GAMEPLAY_H

#include "Przeszkoda.h"
#include <vector>
#include <GamePlay/Player.h>

enum GameState {
    RUNNING, FINISHED
};

class GamePlay {
    Player player;
    std::vector<Przeszkoda> przeszkody;
    int score;
public:
    GamePlay();

    void createPrzeszkoda();

    void update();

    void changeTime(float t) { player.changeTime(t); };

    void resetTime() { player.resetTime(); };

    std::vector<Przeszkoda> getPrzeszkody() { return przeszkody; };

    float getSpeed() { return player.getSpeed(); };

    float getHeight() { return player.getHeight(); };

    int getScore() { return score; };
};


#endif //GAMETEMPLATE_GAMEPLAY_H
