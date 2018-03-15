#pragma once

#include <SFML/Graphics.hpp>
#include <WRenderer.hpp>

class WRendererSFML: public WRenderer{ 
public:
void init();
void update();
void destroy();
void renderObject(const Object obj);
void drawText(std::string str) ;

     void flush();
     void clear();

private:
sf::RenderWindow* _window;
sf::Font* _font;


};