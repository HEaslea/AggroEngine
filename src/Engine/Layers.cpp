#include "../../PCH/pch.hpp"

#include "Layers.hpp"


namespace Layers
{
    LayerStack::LayerStack() {}    

    LayerStack& LayerStack::instance()
    { 
        static LayerStack ls;
        return ls;
    }

    void LayerStack::testOut()   
    { 
        std::cout << "Testing out for layerstack" << std::endl;
    }
}
