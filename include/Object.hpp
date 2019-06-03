#pragma once

#include <Rect.hpp>
#include <SpriteSheet.hpp>
#include <string>
#include <vector>
#include <Animation.hpp>
#include <unordered_map>
#include <Orientation.hpp>
#include <stack>
#include <Vector.hpp>
#include <SFML/System/Vector2.hpp>
#include <Log.hpp>

#include <math.h>       /* atan2 */

#define PI 3.14159265

/**
 * @class Object
 * @brief A small object class
 */
class Object{
public:
    SpriteSheet *icon;
    float y;
    float x;
    
    int _offsetx;
    int _offsety;
        
    std::string _folder;
    Rect *_rect;
    SpriteSheet *_sheet;
    std::string _status;

    //Todas las animaciones
    std::unordered_map<std::string,Animation> _animations;

   // std::vector<SpriteSheet> _Images;  
    std::unordered_map<int,SpriteSheet> _Images;

    void Play(uint32_t time);
    void Action();

    
    //TODO: Move to other site
    std::stack<sf::Vector2f> _movements;

    Orientation _direction;
public:

    void setX(int newVal){
        x = newVal + _offsetx;
    }
    
    void setY(int newVal){
        y = newVal + _offsetx;

    }


	void loadEntity(std::string filename);

    void setStatus(std::string status);
	Object(std::string filename, int x, int y);
    Object(int x, int y, int w, int h);
    SpriteSheet* getSheet(){return _sheet;};
    Rect* getRect(){return _rect;};
    void setDirection(Orientation direction);
    void move();
};