#pragma once

namespace impvm
{

class Core
{
	static Core* ms_instance;

public:
	static Core* Instance();
	static void Release();
	
	
	//draw
	//input
	//addObject
	void processInput();
	void update();
	void render();

private:
	Core();
	~Core();

};

}

