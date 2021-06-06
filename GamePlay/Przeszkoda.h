#ifndef GAMETEMPLATE_PRZESZKODA_H
#define GAMETEMPLATE_PRZESZKODA_H

#include "SFML/Graphics.hpp"

enum typ {
    RAKIETA, POZLASER, SKOSLASER
};

class Przeszkoda {
    sf::Vector2f begin;
    sf::Vector2f end;
    typ type;
    bool OnOff;
public:
    Przeszkoda(typ t);

    void setBegin(sf::Vector2f x) { begin = x; };

    void setEnd(sf::Vector2f x) { end = x; };

    void move(sf::Vector2f vec);

    sf::Vector2f getBegin() { return begin; };

    sf::Vector2f getEnd() { return end; };

    typ getType() { return type; };
};


#endif //GAMETEMPLATE_PRZESZKODA_H
