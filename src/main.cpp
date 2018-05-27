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
    Object *def = new Object("IDEFENDER/IDEFENDER.ENT.XML",300,300);
    Object *elt = new Object("IELITEGUARD/IELITEGUARD.ENT.XML",500,500);
    Object *gld = new Object("RGLADIATOR/RGLADIATOR.ENT.XML", 420 ,180);
    
    myGame->objects.push_back(*gld);
    myGame->objects.push_back(*elt);
    myGame->objects.push_back(*def);

    myGame->loop();

    
    Log::info("END");
}

