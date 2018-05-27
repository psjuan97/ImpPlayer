#pragma once
#include <vector>
#include <Object.hpp>
#include <Game.hpp>

class InputLogic
{
private:
    

    std::vector<Object*> _selecteds;
public:
    InputLogic();
    ~InputLogic();
    
bool checkContais(Object* unit,int firstX, int firstY, int lastX , int lastY);
bool isSpriteClicked ( Object *unit );

void selectObject();
void moveObject();

};

