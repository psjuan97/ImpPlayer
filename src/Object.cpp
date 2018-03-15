#include <Object.hpp>

/**
 * @brief Default Construcor of Object
 * @return nice object with x and y set to 0
 */
Object::Object(){
	this->_x = 0;
	this->_y = 0;	
}



/**
 * @brief Constructor of Object
 * @param x Coord X
 * @param y Coord Y
 */
Object::Object(int x, int y){
	_x = y;
	_y = x;	
}