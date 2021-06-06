#ifndef GAMETEMPLATE_GAMEPLAYCONTROLLER_H
#define GAMETEMPLATE_GAMEPLAYCONTROLLER_H

#include <GamePlay/GamePlay.h>
#include "engine/GameStateController.h"
#include <SFML/Audio.hpp>

class GamePlayController : public GameStateController {
    sf::Sprite sfGracz;
    sf::Texture graczTexture;
    sf::Texture rakietaTexture;
    sf::Texture laserTexture;
    sf::Font font;
    sf::SoundBuffer buffer;
    GamePlay board;
    std::string nextState;
    const int size = 20;
    std::vector<sf::Sprite> sfprzeszkody;
    std::vector<sf::Rect<float >> przeszkodyhitbox; //do wykrywania kolizji

    float score;
public:
    GamePlayController();

    virtual std::string getNextState() const;

    virtual void handleEvent(const sf::Event &event);

    virtual void updateModel();

    virtual void draw(sf::RenderWindow &win);

    virtual void onEnter(const std::string &data);

    virtual std::string onExit();

    void drawPrzeszkody();

    bool hasHit();

    void SoundBoom();

    virtual std::string getDifficulty() { return " ";};
};


#endif //GAMETEMPLATE_GAMEPLAYCONTROLLER_H
