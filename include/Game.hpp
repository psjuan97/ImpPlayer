#pragma once

#include <Render/WRenderer.hpp>
#include <Object.hpp>
#include <vector>


namespace impvm
{

class Game
{
private:
	static Game* ms_instance;
    WRenderer *engine;
    

public:
	static Game* Instance();
	static void Release();
	std::vector<Object> objects;
	
	//draw
	//input
	//addObject
	void processInput();
	void update();
	void render();
    void close(){
            engine->close();
    };
    void loop();
private:
	Game();
	~Game();

};

}

