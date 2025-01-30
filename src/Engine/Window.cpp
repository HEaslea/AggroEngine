#include "../../PCH/pch.hpp"

#include "Window.hpp"

#include <string>



Window::Window(const WindowProperties& props) : _properties(props) { createWindow(); }

Window::Window(unsigned int w, unsigned int h) : _properties({w, h, "AggroEngine"}) { createWindow(); }
 
Window::~Window() 
{ 
    // NEED A LOGGING SYSTEM
    // log(window closed), then app closed
    glfwDestroyWindow(_window);
}

void Window::createWindow()
{ 
    _window = glfwCreateWindow(_properties._width,
        _properties._height, 
        _properties._title.c_str(), NULL, NULL);
    if(!_window)
    { 
        // LOG FATAL ERROR
        // placeholder cout 
        std::cout << "[FATAL ERROR] - WINDOW CREATION FAILED -  window::createWindow" << std::endl;
        glfwTerminate();
        // terminate whole app found within app
    }

    makeCurrentContext();
}


// simple wrapper
void Window::makeCurrentContext()
{ 
    glfwMakeContextCurrent(_window);
}

void Window::setFullScreen() 
{ 
    // primary monitor, research other calls

    // Get Monitor
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    // Get Mode of Monitor
    const GLFWvidmode* monMode = glfwGetVideoMode(monitor);

    // Actually Set Window
    // Will set on main monitor due to earlier call
    // Will change refreshrate
    glfwSetWindowMonitor(_window, monitor, 0, 0, monMode->width, monMode->height, monMode->refreshRate);
}
 
// To allow for my own window callbacksd
bool Window::shouldWindowClose()
{ 
    return glfwWindowShouldClose(_window);
}

void Window::clearColourBuffer()
{ 
    // Implied all channels (?)
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::swapBuffers()
{ 
    glfwSwapBuffers(_window);
}

void Window::pollEvents()
{ 
    
    glfwPollEvents();
}
 
// NEED WRAPPER FOR glfwWindowShouldClose