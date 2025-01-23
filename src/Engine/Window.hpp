#pragma once
 
#include "../../PCH/pch.hpp"


void windowTestOut();

struct WindowProperties
{ 
    unsigned int _width;
    unsigned int _height;

    std::string _title; 

    WindowProperties(unsigned int w, unsigned int h, const std::string& t);
};

class Window 
{ 
    WindowProperties _properties;
public: 

    Window(const WindowProperties&);

    void testOut();
};