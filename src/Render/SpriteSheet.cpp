#include <SpriteSheet.hpp>

#include <algorithm>
#include <string> 
#include <Log.hpp>

using namespace impvm;


SpriteSheet::SpriteSheet(){
    _baseSheet = new sf::Sprite();
    
}

void SpriteSheet::generateRects(){
    
    for(int i=0; i<columns; i++){
        _mold[i] = (std::vector<Rect>());
        for(int j=0; j<rows; j++){
            Rect tmp;
            tmp.h = (height- (rows - 1))/rows ;
            tmp.w = (width - (columns - 1))/columns;
            tmp.x = i * tmp.h + (rows + 1) *i;
            tmp.y = j * tmp.w + (columns +1)*j;//tmp.y = j * tmp.w + (columns -7)*j;
            _mold[i].push_back(tmp);

        }
        
    }
}

void SpriteSheet::setTexture(){
    // Declare and load a texture
    
    
    sf::Image image;
    sf::Texture *texture =  new sf::Texture();
    
    std::string imageName = file+".RLE.BMP"; 
    std::transform(imageName.begin(), imageName.end(), imageName.begin(), ::toupper);

    //texture->loadFromFile(imageName.c_str());
    image.loadFromFile(imageName.c_str());
    image.createMaskFromColor( sf::Color::Green);

    
    // Create a sprite
    texture->loadFromImage(image);



    _baseSheet->setTexture(*texture);

    width = _baseSheet->getGlobalBounds().width;
    height = _baseSheet->getGlobalBounds().height;

    Log::console->info("imageName: {} " ,imageName);
    Log::console->info("width: {} " ,width);
    Log::console->info("height: {} " ,height);


}

SpriteSheet::~SpriteSheet()
{
}

