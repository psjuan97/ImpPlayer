#include <Log.hpp>

using namespace impvm;

std::shared_ptr<spd::logger> Log::console = nullptr;


void Log::info(std::string text){
    

    console->info(text);
}


void Log::warn(std::string text){
    

    console->warn(text);
}


void Log::error(std::string text){
    

    console->critical(text);
}

void Log::init(std::string name){
console =  spd::stdout_color_mt(name);

}
