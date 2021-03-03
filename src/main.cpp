#include <Object.hpp>
#include <Game.hpp>

using namespace std;
using namespace impvm;

namespace spd = spdlog;

int main(int argc, char* argv[]) {
    
    Game* myGame = Game::Instance();
    Object *def = new Object("resource/BHIGHLANDER.SC.XML",300,300);

    
    myGame->objects.push_back(*def);



    myGame->loop();

    
}

