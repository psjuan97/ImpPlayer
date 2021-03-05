#include <SpriteSheet.hpp>

#include <algorithm>
#include <string> 
#include <Log.hpp>
#include <Util.hpp>

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
            tmp.x = i * (tmp.w +1);
            tmp.y = j * (tmp.h +1) ;//j * tmp.w + (columns +1)*j;//tmp.y = j * tmp.w + (columns -7)*j;
            
        //    Log::console->info("tmp.h: {}", tmp.h);
       //     Log::console->info("tmp.y: {}", tmp.y);
            _mold[i].push_back(tmp);

        }
        
    }
}

void SpriteSheet::setTexture(){
    // Declare and load a texture
    
    
    sf::Image image;
    sf::Texture *texture =  new sf::Texture();

    std::vector<std::string> ruta(stringToVector('/', file));
    
    // lo que viene del xml está en minusculas, pero el archivo correspondiente el mayus
    std::string last = ruta[ruta.size() - 1];
    std::transform(last.begin(), last.end(), last.begin(), ::toupper);

    std::string imageName = "";
    for (auto i = 0; i < ruta.size()-1; ++i) {
        imageName += ruta[i] + '/';
    }

    imageName += last+".RLE.BMP";    

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

