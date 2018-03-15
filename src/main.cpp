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



    
    Log::info("Ejemplo de info");
    Log::warn("Ejemplo de warning");
    Log::error("Ejemplo de error ");
    
    myGame->loop();

}

/*
    const int TICKS_PER_SECOND = 50;
    const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
    const int MAX_FRAMESKIP = 10;

    DWORD next_game_tick = GetTickCount();
    int loops;

    bool game_is_running = true;
    while( game_is_running ) {

        loops = 0;
        while( GetTickCount() > next_game_tick && loops < MAX_FRAMESKIP) {
            update_game();

            next_game_tick += SKIP_TICKS;
            loops++;
        }

        display_game();
    }


*/