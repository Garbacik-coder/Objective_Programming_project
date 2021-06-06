#include <sstream>
#include <iostream>
#include "OptionsController.h"


OptionsController::OptionsController() : GameStateController("OPTIONS") {
    nextState = this->getStateID();

    options.resize(3, 1);
    currentOption = 0;

    if (!font.loadFromFile("arial.ttf"))
        abort();
}

void OptionsController::onEnter(const std::string &data) {
    nextState = this->getStateID();
}

std::string OptionsController::onExit() {
    std::stringstream ss;
    ss << "MENU ";
    for (size_t i = 0; i < options.size(); ++i) {
        ss << options[i] << " ";
    }
    return ss.str();
}

OptionsController::~OptionsController() {
    // TODO Auto-generated destructor stub
}

void OptionsController::handleEvent(const sf::Event &event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape) {
            nextState = "MENU";
        }

        if (event.key.code == sf::Keyboard::Up) {
            currentOption -= 1;
            if (currentOption < 0)
                currentOption = options.size() - 1;
        }
        if (event.key.code == sf::Keyboard::Down) {
            currentOption += 1;
            if (currentOption >= options.size())
                currentOption = 0;
        }

        if (event.key.code == sf::Keyboard::Enter) {
            if (currentOption == 0)
                difficulty = "EASY";
            if (currentOption == 1)
                difficulty = "NORMAL";
            if (currentOption == 2)
                difficulty = "HARD";
        }
    }
}

void OptionsController::updateModel() {
}

void OptionsController::draw(sf::RenderWindow &win) {
    float r = 15;
    float x = 530;
    float y = 150;
    float space = 50;

    sf::Text Play;
    Play.setFont(font);
    Play.setString("EASY");
    Play.setPosition(2 * r + x, y);
    Play.setFillColor(sf::Color::Yellow);
    win.draw(Play);

    sf::Text Options;
    Options.setFont(font);
    Options.setString("NORMAL");
    Options.setPosition(2 * r + x, y + space);
    Options.setFillColor(sf::Color::Yellow);
    win.draw(Options);

    sf::Text Scores;
    Scores.setFont(font);
    Scores.setString("HARD");
    Scores.setPosition(2 * r + x, y + 2 * space);
    Scores.setFillColor(sf::Color::Yellow);
    win.draw(Scores);

    sf::CircleShape c(r, 3);
    c.rotate(90);
    c.setPosition(x, y + space * currentOption);
    win.draw(c);

    sf::Text esc;
    esc.setFont(font);
    esc.setString("(Press esc to get back to MENU)");
    esc.setFillColor(sf::Color::Yellow);
    esc.setCharacterSize(win.getSize().x / 60);
    esc.setPosition(0.5 * (win.getSize().x - esc.getLocalBounds().width), win.getSize().y - 50);
    esc.setOutlineThickness(2);
    win.draw(esc);
}

std::string OptionsController::getNextState() const {
    return nextState;
}

std::string OptionsController::getDifficulty() {
    std::cout<<difficulty;
    return difficulty;
}


