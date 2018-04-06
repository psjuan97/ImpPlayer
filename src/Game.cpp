#include "Game.hpp"
#include <Render/RendererEngine.hpp>
#include <Log.hpp>
#include <Clock.hpp>
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

    bool game_is_running = true; 
    

    
    uint32_t lastTime = 0;
            

    objects[0].setStatus("walk");
    

int c = 0;

    while(engine->ready() ){

        engine->clear();
        
        update();
        

        uint32_t currentTime = fpsClk.getPassedTime(); 
        uint32_t fps = 1000.f / (currentTime - lastTime);
        lastTime = currentTime;            
        engine->drawText("FPS: " + std::to_string(fps));
        
        for(int i=0; i<objects.size();i++){
            engine->drawObject(&objects[i]);
            
            
          //  if(c == 100){
                objects[i].Play();
                c = 0;
            //}
            c++;
            
        }
        
        engine->flush();
        
        
    }
   
   
}