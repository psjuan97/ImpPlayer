#pragma once

#include <vector>
#include <string>
#include <Rect.hpp>
#include <SFML/Graphics.hpp>
#include <unordered_map>

class SpriteSheet{
public:
    sf::Sprite *_baseSheet;    
  //  std::vector<> _mold;
    
    std::unordered_map<int,std::vector<Rect>> _mold;
public:
    SpriteSheet();
    ~SpriteSheet();
    

    void setTexture();
    void generateRects();
    //imageAtributes
    int width;
    int height;

    //Imperium atributes
    int idx;
    std::string file;
    std::string drawmode;
    std::string remaping;
    int rows;
    int columns;
    
    
};

