#ifndef GAMETEMPLATE_OPTIONSCONTROLLER_H
#define GAMETEMPLATE_OPTIONSCONTROLLER_H

#include <string>
#include <vector>
#include "engine/GameStateController.h"

class OptionsController : public GameStateController {
    std::string nextState;
    std::string difficulty;

    std::vector<int> options;
    int currentOption;

    sf::Font font;
public:
    OptionsController();
    virtual ~OptionsController();

    virtual std::string getNextState() const;
    virtual void handleEvent ( const sf::Event & event ) ;
    virtual void updateModel() ;
    virtual void draw(sf::RenderWindow & win) ;

    virtual void onEnter(const std::string & data) ;
    virtual std::string onExit() ;

    virtual std::string getDifficulty();
};

#endif //GAMETEMPLATE_OPTIONSCONTROLLER_H
