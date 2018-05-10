#pragma once

#include <SFML/System/Vector2.hpp>


class Vector
{
private:
    sf::Vector2f _vec;

public:
    Vector(float x, float y)
    {
        _vec = sf::Vector2f(x,y);
    }
    
    Vector(const Vector &other)
    {
        this->_vec = other._vec;
    }
    
    ~Vector()
    {
    }

};

