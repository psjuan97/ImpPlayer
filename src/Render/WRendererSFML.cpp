#include <WRendererSFML.hpp>
#include <spdlog/spdlog.h>
#include <iostream>
#include <Log.hpp>

using namespace std;
using namespace sf;
using namespace impvm;

void WRendererSFML::init()
{


this->_window = new RenderWindow(sf::VideoMode(800, 600), "SFML window");
if(_window != nullptr){
    Log::info("SFML Renderer is UP");
     _window->setFramerateLimit(60);
     _font = new sf::Font();
    if (!_font->loadFromFile("game.ttf"))
    {
        Log::error("Error loading font");
    }
}else{
    Log::error("Error initializing SFML Renderer");

}
    
    
}

void WRendererSFML::update()
{
    sf::Event event;
    while (_window->pollEvent(event))
    {
        // Close window: exit
        if (event.type == sf::Event::Closed){
            _ready = false;
            _window->close();     
        }

    }



}

void WRendererSFML::flush(){
    
            _window->display();

}


void WRendererSFML::clear(){
            _window->clear();

}

void WRendererSFML::destroy()
{
    
    
}

void WRendererSFML::drawObject(Object* str){
   sf::IntRect rectangulo = sf::IntRect(str->_rect->x, str->_rect->y, str->_rect->w, str->_rect->h);
   
    str->getSheet()->_baseSheet->setTextureRect(rectangulo);
    _window->draw( *str->getSheet()->_baseSheet);


}


void WRendererSFML::drawText(std::string str){
    
    sf::Text text = sf::Text(str, *_font, 25);
    text.setFillColor(sf::Color::Red);

    _window->draw( text);


}


bool WRendererSFML::ready(){
    return _ready;    
}