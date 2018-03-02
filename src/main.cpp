#include <iostream>
#include <SFML/Graphics.hpp>
//#include "include/Object.hpp"
#include <Object.hpp>
#include <string>
#include <spdlog/spdlog.h>
using namespace std;
namespace spd = spdlog;

int main(int argc, char* argv[]) {

	
	auto console = spd::stdout_color_mt("console");
	console->info("Welcome to spdlog!");
    console->warn("Easy padding in numbers like {:08d}", 12);
    console->critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);

		
  // Code adapted from the SFML 2 "Window" example.


/*
while (true)
{
  processInput();
  update();
  render();
}
*/

  sf::Window App(sf::VideoMode(800, 600), "myproject");
cout << "gola" << endl;
  while (App.isOpen()) {
    sf::Event Event;
    while (App.pollEvent(Event)) {
      if (Event.type == sf::Event::Closed)
	App.close();
    }
    App.display();
  }
  
}