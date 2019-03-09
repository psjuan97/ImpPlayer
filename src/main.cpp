#include <iostream>
#include <SFML/Graphics.hpp>
//#include "include/Object.hpp"
#include <Object.hpp>
#include <string>
#include <spdlog/spdlog.h>


#include <Utils/Log.hpp>
#include <Game.hpp>
#include <Clock.hpp>

using namespace std;
using namespace impvm;

namespace spd = spdlog;

int main(int argc, char* argv[]) {
    
    Game* myGame = Game::Instance();
    Object *def = new Object("BHIGHLANDER/BHIGHLANDER.ENT.XML",300,300);

    
    myGame->objects.push_back(*def);



    myGame->loop();

    
    Log::info("END");
}

