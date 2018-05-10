#include <Object.hpp>
#include "tinyxml2.h"
#include <Log.hpp>

using namespace tinyxml2;
using namespace impvm;

void Object::Play(uint32_t time){
    
    if (time - _animations[_status]._lastTime >= _animations[_status].getVelocity() )
    {
        //si ha pasado tiempo suficiente next frame
    this->_animations[_status].nextFrame();
    _rect = _animations[_status].getActualFrame();
    _animations[_status]._lastTime = time;
   // Log::console->info(_animations[_status].getIFrame());
    }

    
}


void Object::Action(){ // TODO change to pointer
    int speed = 5;
    
    //Vector tmpMovement = _movements.push();
    
    
    
    
}



void Object::setStatus(std::string status){
    _status = status;
    //buscar la animacion correspondiente y asignar
    _sheet = _animations[status].getImage();
    _rect = _animations[status].getActualFrame();
}


/**
 * @brief Default Construcor of Object
 * @return nice object with x and y set to 0
 */
Object::Object(std::string filename, int x, int y){

this->x = x;
this->y = y;

_folder = filename.substr(0, filename.find_last_of('/') +1);

    Log::console->info("    FOLDER: {} " ,_folder);

tinyxml2::XMLDocument doc;
if(doc.LoadFile(filename.c_str()) == tinyxml2::XML_SUCCESS){
    tinyxml2::XMLElement* classElem = doc.FirstChildElement("entity")->FirstChildElement("images");


    //std::unordered_map<std::string,std::string> mymap;

    for (const XMLElement* child = classElem->FirstChildElement(); child!=0; child=child->NextSiblingElement()){
    SpriteSheet Tmpsheet = SpriteSheet();    

    
    
    child->QueryIntAttribute("idx", &Tmpsheet.idx);
    Tmpsheet.file = _folder + child->Attribute("file");
    Tmpsheet.drawmode = child->Attribute("drawmode");
    Tmpsheet.remaping = child->Attribute("remaping");
    child->QueryIntAttribute("rows", &Tmpsheet.rows);
    child->QueryIntAttribute("columns", &Tmpsheet.columns);
    
    Log::console->info("idx: {} " ,Tmpsheet.idx);
    Log::console->info("file: {} " , Tmpsheet.file);
    Log::console->info("rows: {}" , Tmpsheet.rows);
    Log::console->info("columns: {}" , Tmpsheet.columns);
    
    this->_Images[Tmpsheet.idx] = Tmpsheet;
    /*for(const XMLAttribute* attribute = child->FirstAttribute(); attribute!=0; attribute=attribute->Next()){
        
       Log::info(attribute->Name() );//": " << attribute->Value() << endl;
    }*/
    
    }
    
    
    
    //Lets Open the images and save it in 
    for(int i=0; i<_Images.size(); i++){
        Log::console->info("file: {} " , _Images[i].file);

        _Images[i].setTexture();
        _Images[i].generateRects(); // aqui se generan los mold
        
    }
    
    classElem = doc.FirstChildElement("entity")->FirstChildElement("anims");

        Log::console->info("---------------Animations--------------" );

    for (const XMLElement* child = classElem->FirstChildElement(); child!=0; child=child->NextSiblingElement()){
        std::string name;
        name = child->Attribute("name");
        Log::console->info("name: {} " , name);

        //Animations load
        Animation tmpAnim = Animation();
        tmpAnim.setVelocity(66);


        for (const XMLElement* subChild = child->FirstChildElement(); subChild!=0; subChild=subChild->NextSiblingElement()){
        //replace and frame
            Log::console->info("subChild->Name(): {} " , subChild->Name());

            if(std::string("replace").compare( subChild->Name()) == 0 ){
                 Log::console->info("Enter " );
                int imageID;
                subChild->QueryIntAttribute("image", &imageID);
                Log::console->info("image: {} " , imageID);
                
                tmpAnim.setImage(&_Images[imageID]);
                tmpAnim.setFrames(&_Images[imageID]._mold[(int)Orientation::NORTH]); // el 0 se cambiara segun el sentido/orientacion
    
                break;
            }
        


        }
        
        _animations[name] = tmpAnim;
        setStatus(name);
    

    }
    

    
}

}

void Object::setDirection(Orientation direction) // TODO posible fix new direction direct to SetFrames
{
    this->_direction = direction; 
    std::vector<Rect> *newDirection = &_animations[_status].getImage()->_mold[(int)direction];
    _animations[_status].setFrames(newDirection);
    //tmpAnim.setFrames(&_Images[imageID]._mold[(int)Orientation::NORTH]);
}
