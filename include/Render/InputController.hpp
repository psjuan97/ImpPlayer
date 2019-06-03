#pragma once
#include <Object.hpp>
#include <Utils/Vector.hpp>
#include <vector>
#include <map>
#include <string>
#include <Game.hpp>
#include <InputLogic.hpp>

using namespace impvm;



enum InputType
{
    KeyboardInput,
    MouseInput,
    JoystickInput
};
 
struct MyKeys
{
    InputType myInputType;
    sf::Event::EventType myEventType;
    sf::Keyboard::Key myKeyCode;
    sf::Mouse::Button myMouseButton;
};


class InputController
{
private:
    InputController();

    static InputController* instance;
    sf::RenderWindow* _window;
    std::map<std::string,MyKeys> _Keys;

    impvm::InputLogic _logic;


public:
    coord getMousePosition();
    static InputController* getInstance();
    
    bool TestEvent(MyKeys k,sf::Event e);
    void callEvents();
    

    
    void init(sf::RenderWindow* window){
        _window = window;
    };
    ~InputController();

};

