//kod z wykładu
#include <zconf.h>
#include <iostream>
#include <SFML/Audio.hpp>
#include "GameManager.h"

GameManager::GameManager(sf::RenderWindow &win) : window(win) {
    if (!texture.loadFromFile("background.png"))
        abort();
    texture.setRepeated(true);
}

void GameManager::changeState(const std::string &newState) {
    if (stateMap.find(newState) == stateMap.end())
        throw GameStateException(newState);

    std::string rv = "";
    if (currentStatePtr != nullptr)
        rv = currentStatePtr->onExit();

    currentStatePtr = stateMap[newState];
    currentStatePtr->onEnter(rv);
}

void GameManager::run() {

    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("acid.wav"))
        abort();
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setVolume(100);
    sound.setLoop(true);
    sound.play();

    std::string difficulty = "NORMAL";

    float break_time = 2000;
    float x = 0;
    //tło
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(0, 0);
    sprite.setTextureRect(sf::IntRect(x, 0, 1200, 400));
    while (window.isOpen()) {
        std::string currentState = currentStatePtr->getStateID();
        std::string nextState = currentStatePtr->getNextState();

        if (currentState != nextState) {
            changeState(nextState);
        }

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            currentStatePtr->handleEvent(event);
            if (currentState == "OPTIONS")
                difficulty = currentStatePtr->getDifficulty();
        }

        currentStatePtr->updateModel();

        window.clear();

        window.draw(sprite);

        currentStatePtr->draw(window);

        window.display();
        //zwiększanie prędkości w grze i przesuwanie tła
        if (currentState == "GAME") {
            usleep(break_time);
            if (difficulty == "EASY")
                break_time -= 0.015;
            if (difficulty == "NORMAL")
                break_time -= 0.025;
            if (difficulty == "HARD")
                break_time -= 0.04;

            x += 1.5;
            sprite.setTextureRect(sf::IntRect(x, 0, 1200, 400));
        } else
            break_time = 2000;

    }
}

void GameManager::registerState(std::shared_ptr<GameStateController> state) {
    std::string id = state->getStateID();

    stateMap[id] = state;
}