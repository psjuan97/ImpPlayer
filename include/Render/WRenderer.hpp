#pragma once

#include <Object.hpp>
#include <string>
class WRenderer{ 
    //abstract class
public:
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void close() = 0;

    virtual void flush() = 0;
    virtual void clear() = 0;

    virtual void destroy() = 0;
    virtual void drawObject(Object* str)=0 ;
    virtual void drawText(std::string str) = 0;

    virtual bool ready() = 0;
    
    
    
   // virtual ~WRenderer();
//    sf::Text FPS("0", sf::Font::GetDefaultFont(), 25);

};