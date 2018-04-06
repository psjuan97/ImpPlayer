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

//    Object *elt = new Object("IELITEGUARD/IELITEGUARD.ENT.XML");

    Object *gld = new Object("RGLADIATOR/RGLADIATOR.ENT.XML");
    myGame->objects.push_back(*gld);
    //   myGame->objects.push_back(*elt);

    myGame->loop();

    
    Log::info("END");
}

