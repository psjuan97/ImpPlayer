#include <Clock.hpp>


Clock::Clock(){

    
}


uint32_t Clock::getPassedTime(){
    sf::Time elapsed = clock.getElapsedTime();
    uint32_t msec = elapsed.asMilliseconds();
    return msec;
}


void Clock::restart(){
        clock.restart();
}


