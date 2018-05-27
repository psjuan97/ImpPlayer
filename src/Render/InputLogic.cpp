#include "InputLogic.hpp"
#include <InputController.hpp>
#include <Log.hpp>


InputLogic::InputLogic()
{
    
  
}

InputLogic::~InputLogic()
{
}

bool InputLogic::checkContais(Object* unit,int firstX, int firstY, int lastX , int lastY){
	/*cout << "unit->x: " << unit->x << endl;
	cout << "unit->y: " <<  unit->x<< endl;
	cout << "firstX: "  << firstX<< endl;
	cout << "firstY: "  << firstY<< endl;
	cout << "lastX" <<  lastX<< endl;
	cout << "lastY" << lastY << endl;*/

return ((unit->x > firstX && unit->x < lastX && unit->y > firstY && unit->y < lastY) ||
(unit->x < firstX && unit->x > lastX && unit->y < firstY && unit->y > lastY));

}


bool InputLogic::isSpriteClicked ( Object *unit )
{
	
	
	coord mouseP = InputController::getInstance()->getMousePosition();
    
    impvm::Log::console->info("Mouse.x {}", mouseP.x );
    impvm::Log::console->info("Mouse.y {}", mouseP.y);
    
    
	int x = mouseP.x;
	int y = mouseP.y;
	
	
	if( x > unit->x -30
		&& x < unit->x + 30
		&& y > unit->y -30 && y < unit->y + 30
	)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}


void InputLogic::selectObject(){
    for(int i = 0; i < impvm::Game::Instance()->objects.size(); i++){
            
        if(isSpriteClicked( &impvm::Game::Instance()->objects[i]  )){
            _selecteds.push_back(&impvm::Game::Instance()->objects[i]);
            
            impvm::Log::console->warn("Unidad Selecionada" );

            break;
        }
    }

}
				
void InputLogic::moveObject(){
    
            coord mouse = InputController::getInstance()->getMousePosition();
            
            impvm::Log::console->info("Mouse.x {}", mouse.x );
            impvm::Log::console->info("Mouse.y {}", mouse.y);
    
    
            sf::Vector2f vec;
                vec.x = mouse.x;
                vec.y = mouse.y;
                
			for(int i=0; i<_selecteds.size(); i++){
				_selecteds[i]->_movements.push(vec);

			}
			_selecteds.clear();

}