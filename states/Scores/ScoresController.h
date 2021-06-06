#ifndef STATES_INTRO_INTROCONTROLLER_H_
#define STATES_INTRO_INTROCONTROLLER_H_

#include <fstream>
#include "engine/GameStateController.h"

class ScoresController : public GameStateController
{
    std::fstream wyniki;
    const int size = 25;
    sf::Font font;
    sf::RectangleShape pole1;
    sf::RectangleShape pole2;
    std::vector<sf::Text> gwyniki;

	std::string nextState;

public:
	ScoresController();

	virtual std::string getNextState() const;
    virtual void handleEvent ( const sf::Event & event ) ;
    virtual void updateModel() ;
    virtual void draw(sf::RenderWindow & win) ;

    virtual void onEnter(const std::string & data) ;
    virtual std::string onExit() ;

    void score(sf::RenderWindow &w);
    virtual std::string getDifficulty() { return " ";};
};

#endif /* STATES_INTRO_INTROCONTROLLER_H_ */
