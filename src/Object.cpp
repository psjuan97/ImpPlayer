#include <Object.hpp>
#include "tinyxml2.h"
#include <Log.hpp>

using namespace tinyxml2;
using namespace impvm;

void Object::Play(){
    
    //si ha pasado tiempo suficiente next frame
    this->_animations[_status].nextFrame();
    _rect = _animations[_status].getActualFrame();

    Log::console->info(_animations[_status].getIFrame());
    
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
Object::Object(std::string filename){
    

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
    
    
    //Animations load
    Animation tmpAnim = Animation();
    tmpAnim.setVelocity(10);
    tmpAnim.setImage(&_Images[3]);
    tmpAnim.setFrames(&_Images[3]._mold[0]); // el 0 se cambiara segun el sentido/orientacion
    
    _animations["walk"] = tmpAnim;

   
    
    
    
}

}


