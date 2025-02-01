cmake_minimum_required(VERSION 3.30.0)
project(AggroEngine CXX)

#Globbing Source Files
file(GLOB ENGINE_SOURCES ${PROJECT_SOURCE_DIR}/src/Engine/*.cpp)
message(STATUS "Source Files : ${ENGINE_SOURCES}")


add_executable(aggro_main ${ENGINE_SOURCES})

set_target_properties(aggro_main PROPERTIES 
    CXX_STANDARD_REQUIRED ON
    CXX_STANDARD 20
)

#pch's
add_library(precompiled_headers INTERFACE)
target_precompile_headers(precompiled_headers INTERFACE "PCH/pch.hpp")
target_link_libraries(aggro_main PRIVATE precompiled_headers)
 
#general includes in Engine
target_include_directories(aggro_main PRIVATE ${PROJECT_SOURCE_DIR}/src/Engine)
target_include_directories(aggor_main PRIVATE ${PROJECT_SOURCE_DIR}/src/Utils)

# REQUIRED OpenGL
# see openGL CMake documentation 
find_package(OpenGL REQUIRED)
if(NOT OPENGL_FOUND)
    message(FATAL_ERROR "OPENGL Lib NOT FOUND : ")
else() 
    message("FOUND OPENGL")
endif()
target_link_libraries(aggro_main PRIVATE OpenGL::GL)

# External Includes
target_include_directories(aggro_main PRIVATE ${PROJECT_SOURCE_DIR}/src/Externals)

# REQUIRED GLEW
target_link_libraries(aggro_main PRIVATE ${PROJECT_SOURCE_DIR}/src/Externals/glew32s.lib)

# REQUIRED GLFW
target_link_libraries(aggro_main PRIVATE ${PROJECT_SOURCE_DIR}/src/Externals/libglfw3.a)

target_link_libraries(aggro_main PRIVATE 
    user32
    gdi32
    kernel32
)