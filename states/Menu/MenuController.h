#ifndef STATES_OPTIONS_OPTIONSCONTROLLER_H_
#define STATES_OPTIONS_OPTIONSCONTROLLER_H_

#include <string>
#include <SFML/Graphics.hpp>
#include "engine/GameStateController.h"

class MenuController : public GameStateController
{
	std::string nextState;

    std::vector<int> options;
    int currentOption;

    sf::Font font;
public:
	MenuController();
	virtual ~MenuController();

	virtual std::string getNextState() const;
    virtual void handleEvent ( const sf::Event & event ) ;
    virtual void updateModel() ;
    virtual void draw(sf::RenderWindow & win) ;

    virtual void onEnter(const std::string & data) ;
	virtual std::string onExit() ;

    virtual std::string getDifficulty() { return " ";};

};

#endif /* STATES_OPTIONS_OPTIONSCONTROLLER_H_ */
