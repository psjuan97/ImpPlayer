#pragma once

#include <SFML/Graphics.hpp>
#include <WRenderer.hpp>

class WRendererSFML: public WRenderer{ 
public:
    void init();
    void update();
    void destroy();
    void drawText(std::string str) ;
    void drawObject(Object* str) ;

    void flush();
    void clear();

    bool ready();
private:
    sf::RenderWindow* _window;
    sf::Font* _font;
    bool _ready = true;

};