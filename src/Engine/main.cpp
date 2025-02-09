#include "../../PCH/pch.hpp"


#define GLEW_STATIC
#include "../Externals/glew.h"
#include "../Externals/glfw3.h"

#include "Layers.hpp"
#include "Window.hpp"
#include "../Utils/Vector.hpp"
#include "../Utils/Matrix.hpp"
#include "../Utils/Quaternions.hpp"

int main()
{
    /*
    Vector<float, 3> v{0.0f, 1.0f, 0.0f};
    Quaternions::rotateVector(v, 90.0f, {1.0f, 0.0f, 0.0f});
    v.log();
     

    */
    Vector<float, 3> v2{0.0f, 1.0f, 0.0f};
    Quaternions::rotateVector(v2, 180.0f, {1.0f, 0.0f, 0.0f});
    v2.log();

    /* 
    Vector<float, 3> v3{1.0f, 0.0f, 0.0f};
    Quaternions::rotateVector(v3, 90.0f, {0.0f, 1.0f, 0.0f});
    v3.log();
    */



    return 0;
}