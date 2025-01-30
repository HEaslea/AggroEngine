#pragma once
 
#include "../../PCH/pch.hpp"

#include "../Externals/glew.h"
#include "../Externals/glfw3.h"

void windowTestOut();

// Aggregate - POD Plain Old Data
struct WindowProperties
{ 
    unsigned int _width;
    unsigned int _height;

    std::string _title; 

};

class Window 
{ 
    WindowProperties _properties;

    GLFWwindow* _window;

    void createWindow();

public: 

    Window(WindowProperties const&);
    Window(unsigned int w = 1280, unsigned int h = 900);

    ~Window();

    void makeCurrentContext();

    void setFullScreen();
     
    bool shouldWindowClose();

    void clearColourBuffer();

    void swapBuffers();

    // should this be here? 
    void pollEvents();
};