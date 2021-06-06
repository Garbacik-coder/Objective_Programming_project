#include <SFML/Graphics.hpp>
#include "engine/GameManager.h"

#include "states/Scores/ScoresController.h"
#include "states/Menu/MenuController.h"
#include <memory>
#include <states/GamePlay/GamePlayController.h>
#include <states/OptionsContoller/OptionsController.h>

int main() {
    srand(time(NULL));
    sf::RenderWindow win(sf::VideoMode(1200, 400), "Garbacik Game Studio");
    win.setPosition(
            sf::Vector2i((sf::VideoMode::getDesktopMode().width - win.getSize().x) / 2,
                         (sf::VideoMode::getDesktopMode().height - win.getSize().y) / 2));

    GameManager mgr(win);

    mgr.registerState(std::make_shared<ScoresController>());
    mgr.registerState(std::make_shared<MenuController>());
    mgr.registerState(std::make_shared<GamePlayController>());
    mgr.registerState(std::make_shared<OptionsController>());

    mgr.changeState("MENU");

    mgr.run();
}