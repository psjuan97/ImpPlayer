#include "InputController.hpp"
#include <Log.hpp>
using namespace impvm;


InputController *InputController::instance = nullptr;


InputController* InputController::getInstance(){
        if(InputController::instance == nullptr){
            instance = new InputController();
        }
        return instance;
}
InputController::InputController()
{
    
    MyKeys key;

    // Let's bind the left mouse button to the "Shoot" action
    key.myInputType = MouseInput;
    key.myEventType = sf::Event::MouseButtonPressed;
    key.myMouseButton = sf::Mouse::Left;
    _Keys["ClickIzq"] = key;
    
    key.myInputType = MouseInput;
    key.myEventType = sf::Event::MouseButtonPressed;
    key.myMouseButton = sf::Mouse::Right;
    _Keys["ClickDer"] = key;
    
    
    key.myInputType = KeyboardInput;
    key.myEventType = sf::Event::KeyPressed;
    key.myKeyCode = sf::Keyboard::Escape;
    _Keys["Close"] = key;


}

void InputController::callEvents(){
    sf::Event e;
    
      while(  _window->pollEvent(e)){
          
        if (TestEvent(_Keys["ClickIzq"],e))
            {
                Log::console->info("ClickIzq" );
                _logic.selectObject();
                
            }else if(TestEvent(_Keys["ClickDer"],e)){
                    Log::console->info("ClickDer" );
                      _logic.moveObject();

            }else if(TestEvent(_Keys["Close"],e)){
                Game::Instance()->close();
                
            }
            
    
          
        }


    
}


InputController::~InputController()
{
}

coord InputController::getMousePosition()
{
    coord mouse;
    mouse.x = sf::Mouse::getPosition(*_window).x;
    mouse.y = sf::Mouse::getPosition(*_window).y;
    


    return mouse;
}

bool InputController::TestEvent(MyKeys k,sf::Event e)
{

    //_window->pollEvent(e);
    
   // Log::console->info("PollinEvents" );

    // Mouse event
    if (k.myInputType == MouseInput &&
        k.myEventType == e.type &&
        k.myMouseButton == e.mouseButton.button)
    {
        return (true);
    }
    // Keyboard event
    if (k.myInputType == KeyboardInput &&
        k.myEventType == e.type &&
        k.myKeyCode == e.key.code)
    {
        return (true);
    }
    

    
    
    return (false);
        
        
    

}