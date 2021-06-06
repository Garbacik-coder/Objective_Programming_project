#include "ScoresController.h"
#include <iostream>

ScoresController::ScoresController() : GameStateController("SCORES") {
    nextState = this->getStateID();
    if (!font.loadFromFile("arial.ttf"))
        abort();
    pole1.setSize(sf::Vector2f(size, size));
    pole1.setFillColor(sf::Color(0, 0, 102));
    pole2.setSize(sf::Vector2f(size, size));
    pole2.setFillColor(sf::Color(0, 0, 204));
}

void ScoresController::onEnter(const std::string &data) {
    std::cout << data << std::endl;
    nextState = this->getStateID();
}

std::string ScoresController::onExit() {
    return "";
}

void ScoresController::handleEvent(const sf::Event &event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape) {
            nextState = "MENU";
        }
    }
}

void ScoresController::updateModel() {
}

void ScoresController::draw(sf::RenderWindow &win) {
    gwyniki.clear();
    score(win);
    sf::Text top;
    top.setFont(font);
    top.setString("TOP 3 SCORES");
    top.setFillColor(sf::Color::Yellow);
    top.setCharacterSize(win.getSize().x / 15);
    top.setPosition(0.5 * (win.getSize().x - top.getLocalBounds().width), win.getSize().y / 20);
    top.setOutlineThickness(2);
    win.draw(top);

    for (size_t i = 0; i < gwyniki.size(); ++i) {
        win.draw(gwyniki[i]);
    }

    sf::Text esc;
    esc.setFont(font);
    esc.setString("(Press esc to get back to MENU)");
    esc.setFillColor(sf::Color::Yellow);
    esc.setCharacterSize(win.getSize().x / 60);
    esc.setPosition(0.5 * (win.getSize().x - esc.getLocalBounds().width), win.getSize().y - 50);
    esc.setOutlineThickness(2);
    win.draw(esc);
}

std::string ScoresController::getNextState() const {
    return nextState;
}

void ScoresController::score(sf::RenderWindow &w) {
    std::vector<int> wyniki1;
    int iwynik;
    std::string swynik;
    wyniki.open("wyniki.txt", std::ios::in);
    if (!wyniki.good())
        std::cout << "Błąd oczytu wyników";
    //z pliku do wektora intów (żeby móc sortować)
    while (std::getline(wyniki, swynik)) {
        iwynik = std::stoi(swynik);
        wyniki1.push_back(iwynik);
    }
    std::sort(wyniki1.begin(), wyniki1.end());
    //z wektora intów do wektora tekstów SFML
    int numer = 1;
    for (size_t i = (wyniki1.size() - 1); numer <= 3; --i, ++numer) {
        sf::Text text;
        text.setFont(font);
        text.setString(std::to_string(numer) + ". " + std::to_string(wyniki1[i]));
        text.setFillColor(sf::Color::Yellow);
        text.setCharacterSize(w.getSize().x / 25);
        text.setOutlineThickness(1);
        text.setPosition(0.5 * (w.getSize().x - text.getLocalBounds().width), w.getSize().y / 6 * (numer + 1));
        gwyniki.push_back(text);
    }
    wyniki.close();
}
