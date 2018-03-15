#include <SFML/Graphics.hpp>

class Clock{
private:
    sf::Clock clock;
    
public:
	Clock();
    uint32_t getPassedTime();
    void restart();

};