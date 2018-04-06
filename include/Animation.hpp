#pragma once

#include <vector>
#include <SpriteSheet.hpp>
#include <Rect.hpp>

class Animation{
private:
    int _velocity;
    SpriteSheet* _image;
    std::vector<Rect> *_frames;
    int iFrame = 0;
public:
    int getIFrame(){
       return iFrame; 
    }

    void setVelocity(int vel){_velocity = vel;};
    int getVelocity(){return _velocity;};
    
    void setFrames(std::vector<Rect> * frames){_frames = frames;};
    std::vector<Rect> * getFrames(){return _frames;};

    
    Rect* getActualFrame(){
        return &(*_frames)[iFrame];
    };
    
    void nextFrame(){
        if(iFrame++ == _frames->size()-1){
            iFrame = 0;
        }
    };
    
    
    void setImage(SpriteSheet* image){
        _image = image;
        
    };
    SpriteSheet* getImage(){return _image;};
    uint32_t _lastTime;

    Animation();
    ~Animation();

};

