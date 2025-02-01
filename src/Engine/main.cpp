#include "../../PCH/pch.hpp"


#define GLEW_STATIC
#include "../Externals/glew.h"
#include "../Externals/glfw3.h"

#include "Layers.hpp"
#include "Window.hpp"
#include "../Utils/Vector.hpp"

int main()
{
    Vector<float, 3> g{1.0, 2.0, 3.0};
    Vector<float, 3> f{4.0, 5.0, 9.0};

    auto n = Vectors::project(g, f);

    n.log();
     
    std::cout << Math::getDeg(Vectors::angleBetween(g, f)) << std::endl;;

    return 0;
}