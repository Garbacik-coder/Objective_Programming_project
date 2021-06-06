#include "MenuController.h"
#include <sstream>

MenuController::MenuController() : GameStateController("MENU") {
    nextState = this->getStateID();

    options.resize(4, 1);
    currentOption = 0;

    if (!font.loadFromFile("arial.ttf"))
        abort();
}

void MenuController::onEnter(const std::string &data) {
    nextState = this->getStateID();
}

std::string MenuController::onExit() {
    std::stringstream ss;
//    ss << "MENU ";
//    for (size_t i = 0; i < options.size(); ++i) {
//        ss << options[i] << " ";
//    }
    return ss.str();
}

MenuController::~MenuController() {
    // TODO Auto-generated destructor stub
}

void MenuController::handleEvent(const sf::Event &event) {
    if (event.type == sf::Event::KeyPressed) {
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
                nextState = "GAME";
            if (currentOption == 1)
                nextState = "OPTIONS";
            if (currentOption == 2)
                nextState = "SCORES";
            if (currentOption == 3)
                abort();
        }
    }
}

void MenuController::updateModel() {
}

void MenuController::draw(sf::RenderWindow &win) {
    float r = 15;
    float x = 530;
    float y = 150;
    float space = 50;

    sf::Text Play;
    Play.setFont(font);
    Play.setString("PLAY");
    Play.setPosition(2 * r + x, y);
    Play.setFillColor(sf::Color::Yellow);
    win.draw(Play);

    sf::Text Options;
    Options.setFont(font);
    Options.setString("OPTIONS");
    Options.setPosition(2 * r + x, y + space);
    Options.setFillColor(sf::Color::Yellow);
    win.draw(Options);

    sf::Text Scores;
    Scores.setFont(font);
    Scores.setString("SCORES");
    Scores.setPosition(2 * r + x, y + 2 * space);
    Scores.setFillColor(sf::Color::Yellow);
    win.draw(Scores);

    sf::Text EXIT;
    EXIT.setFont(font);
    EXIT.setString("EXIT");
    EXIT.setPosition(2 * r + x, y + 3 * space);
    EXIT.setFillColor(sf::Color::Yellow);
    win.draw(EXIT);

    sf::Text Hello;
    Hello.setFont(font);
    Hello.setString("HELLO!");
    Hello.setCharacterSize(100);
    Hello.setPosition(win.getSize().x / 2 - Hello.getGlobalBounds().width / 2, 15);
    Hello.setFillColor(sf::Color::Yellow);
    win.draw(Hello);

    sf::CircleShape c(r, 3);
    c.rotate(90);
    c.setPosition(x, y + space * currentOption);
    win.draw(c);
}

std::string MenuController::getNextState() const {
    return nextState;
}