#pragma once

#include <Rect.hpp>
#include <SpriteSheet.hpp>
#include <string>
#include <vector>
#include <Animation.hpp>
#include <unordered_map>

/**
 * @class Object
 * @brief A small object class
 */
class Object{
public:
    std::string _folder;
    Rect *_rect;
    SpriteSheet *_sheet;
    std::string _status;

    //Todas las animaciones
    std::unordered_map<std::string,Animation> _animations;

   // std::vector<SpriteSheet> _Images;  
    std::unordered_map<int,SpriteSheet> _Images;

    void Play();
public:
    void setStatus(std::string status);
	Object(std::string filename);
    Object(int x, int y, int w, int h);
    SpriteSheet* getSheet(){return _sheet;};
    Rect* getRect(){return _rect;};



};