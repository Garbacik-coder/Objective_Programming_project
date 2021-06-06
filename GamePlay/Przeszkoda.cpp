#include "Przeszkoda.h"

Przeszkoda::Przeszkoda(typ t) {
    type=t;
}

void Przeszkoda::move(sf::Vector2f vec) {
    begin -= vec;
    end -= vec;
    return;
}