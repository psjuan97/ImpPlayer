#include "Game.hpp"
#include <Render/RendererEngine.hpp>
#include <Log.hpp>
#include <Clock.hpp>
#include <InputController.hpp>

impvm::Game* impvm::Game::ms_instance = nullptr;

impvm::Game::Game(){
    //lets inicilice all components
        //renderer
        //log system
    Log::init("Impv");
    Log::info("Init Renderer...");
    engine = RendererEngine::p();
    engine->init();
}

impvm::Game::~Game()
{
}

impvm::Game* impvm::Game::Instance()
{
	if (ms_instance == nullptr) {
		ms_instance = new impvm::Game();
	}
	return ms_instance;
}

void impvm::Game::Release()
{
	if (ms_instance) {
		delete ms_instance;
	}
	ms_instance = nullptr;
}



void impvm::Game::processInput(){

}

void impvm::Game::update(){
    engine->update();

}

void impvm::Game::render(){
}

void impvm::Game::loop(){

	
    Clock fpsClk = Clock();
    Clock animClk = Clock();

    bool game_is_running = true; 
    
    uint32_t lastTime = 0;
            
    objects[0].setStatus("walk");
    objects[1].setStatus("Attack");
    objects[2].setStatus("Die");
    
        
    objects[0].setDirection(Orientation::SOUTH);
    objects[1].setDirection(Orientation::NORTH);
    objects[2].setDirection(Orientation::NORTHEAST);

#include <SFML/System/Vector2.hpp>

   // Vector destiny(400,400);
    sf::Vector2f destiny(600,95);
    sf::Vector2f destiny2(400,75);

    objects[0]._movements.push(destiny);
    objects[0]._movements.push(destiny2);

   // objects[0].setStatus("Idle");

    int c = 0;

    while(engine->ready() ){

        
       InputController::getInstance()->callEvents();
        
        engine->clear();
        
       // update();
        

        uint32_t currentTime = fpsClk.getPassedTime(); 
        uint32_t fps = 1000.f / (currentTime - lastTime);
        lastTime = currentTime;            
        engine->drawText("FPS: " + std::to_string(fps));
        
        for(int i=0; i<objects.size();i++){
           // Log::console->info("---Draw: ");

            engine->drawObject(&objects[i]);
            
          /// if(c == 100){
                          //Log::console->info("---Play: ");

                objects[i].Play(currentTime);
               // c = 0;
           // }
           // c++;
           
           objects[i].Action();
            objects[i].move();

            
        }
        
        engine->flush();
        
        
    }
   
   
}