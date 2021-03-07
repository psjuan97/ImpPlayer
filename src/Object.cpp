#include <Object.hpp>
#include "tinyxml2.h"
#include "EntityLoader.hpp"

using namespace tinyxml2;
using namespace impvm;

void Object::Play(uint32_t time){
    
    if (time - _animations[_status]._lastTime >= _animations[_status].getActualVelocity() )
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
    
    //TODO fix
    setDirection(_direction);
    
   // Log::console->info("    DIRECTION: {} " ,_folder);
}



Object::Object(std::string filename, int x, int y){
    this->x = x -72;
    this->y = y -95;

    
    
    std::string entityFile = "";
    EntityLoader el;
    entityFile = el.getEntityRoute(filename);
    
    loadEntity(entityFile);


    //icon = nullptr;
//
    //tinyxml2::XMLDocument doc;
    //if(doc.LoadFile(filename.c_str()) == tinyxml2::XML_SUCCESS){
    //    tinyxml2::XMLElement* classElem = doc.FirstChildElement("class");
    //    const char* entiFilename;
    //    entiFilename = classElem->Attribute ("entity");
    //    loadEntity(std::string(entiFilename));
    //}
    //tinyxml2::XMLElement* classElem = doc.FirstChildElement("class");

    //Log::console->info("Getting atributes.. " );

    //for (const XMLElement* child = classElem->FirstChildElement(); child!=0; child=child->NextSiblingElement()){
    //    try{
    //        std::string icon = child->Attribute("icon");
    //            Log::console->info("icon: {} " ,icon);
//
    //        SpriteSheet *Tmpsheet = new SpriteSheet();    
    //        Tmpsheet->file = icon;
    //        Tmpsheet->rows = 1;
    //        Tmpsheet->columns = 1;
    //        Tmpsheet->setTexture();
    //        Tmpsheet->generateRects();
//
    //        this->icon = Tmpsheet;
//
    //    }catch(...){
//
    //    }
    //}


}

/**
 * @brief Default Construcor of Object
 * @return nice object with x and y set to 0
 */
void Object::loadEntity(std::string filename){

 _folder = filename.substr(0, filename.find_last_of('/') +1);
    Log::console->info("    FOLDER: {} " ,_folder);



tinyxml2::XMLDocument doc;
Log::console->info("EntFile.xml = : {} " ,filename.c_str());
if(doc.LoadFile(filename.c_str()) == tinyxml2::XML_SUCCESS){
    tinyxml2::XMLElement* classElem = doc.FirstChildElement("entity")->FirstChildElement("images");

    Log::console->info("procces EntFile" );

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
    
    
    for (auto &it : _Images){
        Log::console->warn("fileNAME: {} " , it.second.file); // Se esta generando una Images_ VAcia

        it.second.setTexture();
        it.second.generateRects();
    } 
    
    
    

    classElem = doc.FirstChildElement("entity")->FirstChildElement("layers");

        Log::console->info("---------------Layers--------------" );
 
        
    for (const XMLElement* child = classElem->FirstChildElement(); child!=0; child=child->NextSiblingElement()){


        child->QueryIntAttribute("offsetx", &_offsetx);
        child->QueryIntAttribute("offsety", &_offsety);
        break;
        Log::console->info("offsetx: {} " , _offsetx);




    }
    
    
    
    classElem = doc.FirstChildElement("entity")->FirstChildElement("anims");

        Log::console->info("---------------Animations--------------" );

    for (const XMLElement* child = classElem->FirstChildElement(); child!=0; child=child->NextSiblingElement()){
        std::string name;
        name = child->Attribute("name");
        Log::console->info("name: {} " , name);

        //Animations load
        Animation tmpAnim = Animation();

        // TODO ahora se ignoran las sombras
        bool sombras = true;
        for (const XMLElement* subChild = child->FirstChildElement(); subChild!=0; subChild=subChild->NextSiblingElement()){
        //replace and frame
            Log::console->info("subChild->Name(): {} " , subChild->Name());

            if(std::string("replace").compare( subChild->Name()) == 0 && sombras){
                sombras = false;
                 Log::console->info("Enter " );
                int imageID;
                subChild->QueryIntAttribute("image", &imageID);
                Log::console->info("image: {} " , imageID);
                
                tmpAnim.setImage(&_Images[imageID]);
              tmpAnim.setFrames(&_Images[imageID]._mold[(int)Orientation::NORTH]); // el 0 se cambiara segun el sentido/orientacion
    
              //  break;
            }else if(std::string("frame").compare( subChild->Name()) == 0 ){
                int idx,duration;
                subChild->QueryIntAttribute("idx", &idx);
                Log::console->info("idx: {} " , idx);

                subChild->QueryIntAttribute("duration", &duration);
                Log::console->info("duration: {} " , duration);

                tmpAnim.addVelocity(duration);

    
            }
        


        }
        
        _animations[name] = tmpAnim;
        _direction = Orientation::NORTH;
        setStatus(name);
    

    }
    

    
}else{

        Log::console->error("Error al abrir el fichero: {} " ,filename);

}

}

void Object::setDirection(Orientation direction) // TODO posible fix new direction direct to SetFrames
{
    this->_direction = direction; 
    std::vector<Rect> *newDirection = &_animations[_status].getImage()->_mold[(int)direction];
    _animations[_status].setFrames(newDirection);
    //tmpAnim.setFrames(&_Images[imageID]._mold[(int)Orientation::NORTH]);
}


  void Object::move(){
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
            setStatus("idle");

            //impvm::Log::console->error("Empty Stack of movement");
        }
    }