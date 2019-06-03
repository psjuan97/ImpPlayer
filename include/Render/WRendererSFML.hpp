#pragma once

#include <SFML/Graphics.hpp>
#include <WRenderer.hpp>

class WRendererSFML: public WRenderer{ 
public:


    void init();
    void update();
    void close();

    void destroy();
    void drawText(std::string str) ;
    void drawObject(Object* str) ;
    void drawHud();
    void flush();
    void clear();

    bool ready();

    void setFocusObject(Object* str);

private:
    sf::RenderWindow* _window;
    sf::Font* _font;
    sf::Event* _event;

    bool _ready = true;

    Object* _focusObject;
};