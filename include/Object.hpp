#pragma once

#include <Rect.hpp>
#include <SpriteSheet.hpp>
#include <string>
#include <vector>
#include <Animation.hpp>
#include <unordered_map>
#include <Orientation.hpp>
#include <stack>
#include <Vector.hpp>
#include <SFML/System/Vector2.hpp>
#include <Log.hpp>

#include <math.h>       /* atan2 */

#define PI 3.14159265

/**
 * @class Object
 * @brief A small object class
 */
class Object{
public:
    float y;
    float x;
    
    int _offsetx;
    int _offsety;
        
    std::string _folder;
    Rect *_rect;
    SpriteSheet *_sheet;
    std::string _status;

    //Todas las animaciones
    std::unordered_map<std::string,Animation> _animations;

   // std::vector<SpriteSheet> _Images;  
    std::unordered_map<int,SpriteSheet> _Images;

    void Play(uint32_t time);
    void Action();

    
    //TODO: Move to other site
    std::stack<sf::Vector2f> _movements;

    Orientation _direction;
public:

    void setX(int newVal){
        x = newVal + _offsetx;
    }
    
    void setY(int newVal){
        y = newVal + _offsetx;

    }



    void setStatus(std::string status);
	Object(std::string filename, int x, int y);
    Object(int x, int y, int w, int h);
    SpriteSheet* getSheet(){return _sheet;};
    Rect* getRect(){return _rect;};
    void setDirection(Orientation direction);
    void move(){
        if(!_movements.empty()){
            sf::Vector2f Destination = _movements.top();
            setStatus("walk");

          //  impvm::Log::console->warn("Destination.x = {}", Destination.x);
          //  impvm::Log::console->warn("Destination.y = {}", Destination.x);

            sf::Vector2f Origin(x,y);
            sf::Vector2f Direction = Destination - Origin;
            float Speed = 1.5f;


            impvm::Log::console->info("x {}", x );
            impvm::Log::console->info("y {}", y );
            
                        impvm::Log::console->info("----------" );

            impvm::Log::console->info("Origin x {}", Origin.x );
            impvm::Log::console->info("Origin y {}", Origin.y );
   
            float Distance = sqrt( (Destination.x - Origin.x) * (Destination.x - Origin.x) + (Destination.y - Origin.y) *  (Destination.y - Origin.y) );
            Direction /= Distance;
            
             sf::Vector2f finalVector = Origin + Direction * Speed;
            
           // impvm::Log::console->warn("finalVector.x = {}", finalVector.x);
           // impvm::Log::console->warn("finalVector.y = {}", finalVector.x);
             
             if(Distance <= 1){
                _movements.pop();
            impvm::Log::console->warn("Poping movement");

            }else{
                
                this->x = finalVector.x;
                this->y = finalVector.y;
                
                int compass = (((int)round( ( atan2(Destination.y - Origin.y, Destination.x - Origin.x) - (PI/2)) / ( (float)(2*PI) / 8) )) + 8) % 8;

                setDirection( (Orientation)compass);


                }

        }else{
            setStatus("Idle");

           // impvm::Log::console->error("Empty Stack of movement");
        }
    }
};