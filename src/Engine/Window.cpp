#include "../../PCH/pch.hpp"

#include "Window.hpp"

#include <string>

void windowTestOut()
{ 
    std::cout << "Window Test Out" << std::endl;
}

WindowProperties::WindowProperties(unsigned int w = 1280,
        unsigned int h = 900, 
        const std::string& t = "Default Aggro Engine")  : 
        _width(w), _height(h), _title(t) {}
    

Window::Window(const WindowProperties& props) : _properties(props) {}


void Window::testOut()
{ 
    std::cout << "WINDOW TEST OUT : h: " << _properties._height << " w: " << _properties._width << " title: " << _properties._title << std::endl;
}