#pragma once

//#include <WRenderer.hpp>

class WRenderer;
class RendererEngine{
private:
    //pointer to WRender
    static WRenderer* _wrenderer;
    RendererEngine();
public:
    //void switchRender();
    
    static WRenderer* p(); 
    
    
};