#include <RendererEngine.hpp>
#include <WRendererSFML.hpp>


WRenderer *RendererEngine::_wrenderer = nullptr;

RendererEngine::RendererEngine(){
    _wrenderer = new WRendererSFML();
}

WRenderer* RendererEngine::p(){
    if(_wrenderer == nullptr){ // if is null
        RendererEngine();
    }
    
    return _wrenderer;
    
}