#include "Core.hpp"
#include <cstdlib> // NULL 
#include <iostream>
impvm::Core* impvm::Core::ms_instance = NULL;

impvm::Core::Core()
{
}

impvm::Core::~Core()
{
}

impvm::Core* impvm::Core::Instance()
{
	if (ms_instance == NULL) {
		ms_instance = new impvm::Core();
	}
	return ms_instance;
}

void impvm::Core::Release()
{
	if (ms_instance) {
		delete ms_instance;
	}
	ms_instance = NULL;
}



void impvm::Core::processInput(){
	std::cout << "[!]checking input" << std::endl;
}

void impvm::Core::update(){
	
}

void impvm::Core::render(){
	
}
