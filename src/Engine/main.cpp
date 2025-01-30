#include "../../PCH/pch.hpp"


#define GLEW_STATIC
#include "../Externals/glew.h"
#include "../Externals/glfw3.h"

#include "Layers.hpp"
#include "Window.hpp"

int main()
{
    // put into app, keep main clear
    if(!glfwInit())
    { 
        std::cout << "FAILED INIT" << std::endl;
        return -1;
    }

    Window w;

    w.setFullScreen();
    
    while(!w.shouldWindowClose())
    { 
        w.clearColourBuffer();

        w.swapBuffers();
        w.pollEvents();
    }

    w.~Window();

    // this needs to be in app
    glfwTerminate();

    return 0;
}