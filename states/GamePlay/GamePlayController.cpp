#include "GamePlayController.h"
#include <iostream>
#include <fstream>
#include <zconf.h>

//rozmiar planszy 60x20
GamePlayController::GamePlayController() : GameStateController("GAME") {
    if (!graczTexture.loadFromFile("Statek.png"))
        abort();

    if (!buffer.loadFromFile("acid.wav"))
        abort();
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setVolume(100);
    sound.play();

    sfGracz.setTexture(graczTexture);
    sfGracz.rotate(90);
    sfGracz.setScale(1.2, 1.2);

    if (!rakietaTexture.loadFromFile("rakieta.png"))
        abort();

    if (!laserTexture.loadFromFile("laser.png"))
        abort();

    if (!font.loadFromFile("arial.ttf"))
        abort();

    przeszkodyhitbox.clear();
    board = GamePlay();
    nextState = this->getStateID();
    score = 0;
}

void GamePlayController::onEnter(const std::string &data) {
    std::cout << data << std::endl;
    nextState = this->getStateID();
}

std::string GamePlayController::onExit() {
    return "";
}

void GamePlayController::handleEvent(const sf::Event &event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::P) {
            board.createPrzeszkoda();
        }
        if (event.key.code == sf::Keyboard::Up) {
            board.changeTime(0.006);
        }
        if (event.key.code == sf::Keyboard::Down) {
            board.changeTime(-0.006);
        }
    } else { board.resetTime(); }
}

void GamePlayController::updateModel() {
    score += 0.001;
    board.update();
    if (hasHit()) {
        sf::SoundBuffer buffer;
        if (!buffer.loadFromFile("boom.ogg"))
            abort();
        sf::Sound sound;
        sound.setBuffer(buffer);
        sound.setVolume(100);
        sound.play();
        usleep(500000);

        std::fstream wynikiz;
        wynikiz.open("wyniki.txt", std::ios::out | std::ios::app);
        wynikiz << score << std::endl;
        wynikiz.close();
        score = 0;

        nextState = "SCORES";
        board = GamePlay();
    }
    sfprzeszkody.clear();
}

void GamePlayController::draw(sf::RenderWindow &win) {
    sfGracz.setPosition(80, size * (19 - board.getHeight()));

    drawPrzeszkody();
    for (auto &i : sfprzeszkody) {
        win.draw(i);
    }

    win.draw(sfGracz);

    sf::Text wynik;
    wynik.setFont(font);
    int iwynik = score;
    std::string swynik = std::to_string(iwynik);
    wynik.setString(swynik);
    wynik.setPosition(10, 10);
    wynik.setCharacterSize(40);
    wynik.setFillColor(sf::Color::Yellow);
    wynik.setOutlineColor(sf::Color::Black);
    wynik.setOutlineThickness(3);
    win.draw(wynik);
}

std::string GamePlayController::getNextState() const {
    return nextState;
}

void GamePlayController::drawPrzeszkody() {
    std::vector<Przeszkoda> przeszkody = board.getPrzeszkody();

    for (auto &i : przeszkody) {
        if (i.getType() == RAKIETA) {
            sf::Sprite s;
            s.setTexture(rakietaTexture);
            s.rotate(-90);
            s.setScale(1.5, 1.5);
            s.setPosition(i.getBegin().x * size, (19 - i.getBegin().y) * size);
            sfprzeszkody.push_back(s);
        }
        if (i.getType() == POZLASER) {
            sf::Sprite s;
            s.setTexture(laserTexture);
            s.setScale((i.getEnd().x - i.getBegin().x) / size, 0.6);
            s.setPosition(i.getBegin().x * size, (19 - i.getBegin().y) * size);
            sfprzeszkody.push_back(s);
        }
    }
}

bool GamePlayController::hasHit() {
    for (auto &i : sfprzeszkody) {
        if (sfGracz.getGlobalBounds().intersects(i.getGlobalBounds())) {
            return true;
        }
    }
    return false;
}

void GamePlayController::SoundBoom() {
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("boom.ogg"))
        abort();
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setVolume(100);
    sound.play();
}
