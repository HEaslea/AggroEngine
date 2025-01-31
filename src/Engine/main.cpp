#include "../../PCH/pch.hpp"


#define GLEW_STATIC
#include "../Externals/glew.h"
#include "../Externals/glfw3.h"

#include "Layers.hpp"
#include "Window.hpp"
#include "../Utils/Vector.hpp"

int main()
{
    Vector<int, 3> g{1, 2, 3};
    Vector<int, 3> f{4, 5, 6};

    auto n = g.cross(f);

    n.log();

    Vector<int, 2> x{1, 2};
    Vector<int, 2> y{3, 4};

    std::cout << x.cross(y) << std::endl;

    return 0;
}