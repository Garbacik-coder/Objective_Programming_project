#include "GamePlay.h"

GamePlay::GamePlay() {
    player = Player();
    przeszkody.clear();
    score = 0;
}

void GamePlay::update() {
    player.changeSpeed();
    player.move();
    int x = rand() % 400;
    if (x == 0) {
        createPrzeszkoda();
    }
    for (auto &i : przeszkody) {
        i.move(sf::Vector2f(0.09, 0));
    }
    //usuwanie przeszkód poza ekranem
    for (size_t i = 0; i < przeszkody.size(); i++) {
        if (przeszkody[i].getEnd().x < 0) {
            for (size_t j = i; j < przeszkody.size(); j++) {
                przeszkody[j] = przeszkody[j + 1];
            }
            przeszkody.erase(przeszkody.end() - 1);
        }
    }
}

void GamePlay::createPrzeszkoda() {
    int x = rand() % 2;
    int height = rand() % 20;
    switch (x) {
        case 0: {
            Przeszkoda y(RAKIETA);
            y.setBegin(sf::Vector2f(60, height));
            y.setEnd(sf::Vector2f(60, height));
            przeszkody.push_back(y);
            break;
        }
        case 1: {
            Przeszkoda y(POZLASER);
            int length = rand() % 40 + 1;
            y.setBegin(sf::Vector2f(60, height));
            y.setEnd(sf::Vector2f(60 + length, height));
            przeszkody.push_back(y);
            break;
        }
        case 2: {
            Przeszkoda y(SKOSLASER);
            przeszkody.push_back(y);
            break;
        }
        default:
            throw "błąd createPrzeszkoda";
    }
}