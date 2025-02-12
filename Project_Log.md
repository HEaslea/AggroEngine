# Aggro Engine
##### For Personal Use

## Project Overall Goal: 
Produce an engine, allowing for the user to set up scenarios, for scripting AI behaviour on user models. 

Set up using CMake O

3rd Party SDK's : OPENGL : PhysX


ERROR : _drectve errors due to MSVC compiled GLFW3.lib, sourced GLFW again with Ninja

Will Reconfigure Organisation upon clean test run of first window

GOAL : Add a Meta Maths Lib : Vector
GOAL : Add Meta ECS settings Lib : 
GOAL : Learn More About ECS Pattern to optimize (Structs of Arrays // Arrays of Structs etc.)

GOAL : Add scripting capabilities for game AI
 
GOAL : Write on string system that will hash rather than rely on heap performance if need be. 

#### TODO NEXT:

 1. EVENT SYSTEM -> See Cherno vid
    : The idea being that the window should not know about APP: Therefore when it needs the app to respond to a callback, it will construct an AGGRO EVENT and will use that to update whatever we need

 2. LAYER SYSTEM -> See Cherno vid again
    : Events and for graphics
    
 3. LOGGING SYSTEM -> Write My Own



#layers
## Layers

Another dimension
Objects on a layer

Objects will require a script component



### ECS
##### ENTITY COMPONENT SYSTEM
The idea being contiguous data : Structs of Arrays or Arrays of Structs
Structs of Arrays -> Requiring a Management System which is harder to implement
With a Layer Stack -> Arrays of Structs might make the most sense (O(n + m) -> m being the worst case size of each Component);
 

Header Utility becoming more obvious with template classes, where the interface is most important. 



## Learning Opportunities
Why Default args only in Header files? 

Template Error Codes

Unpacking External Dependencies using CMAKE
 
Thread safey through most systems eg. Logging
 
Exception safety - where to apply? 

Copy Elision

Remember Rule of 5

Keep it portable - <cmath>` is portable (as far as I'm aware)
 
Template class name injection

Really nail SFINAE - Vector cross product -> 

# VIDMODE STRUCT REFERENCE
typedef struct GLFWvidmode {
    int width;        // The width of the mode in pixels
    int height;       // The height of the mode in pixels
    int redBits;      // The number of bits for the red channel
    int greenBits;    // The number of bits for the green channel
    int blueBits;     // The number of bits for the blue channel
    int refreshRate;  // The refresh rate of the monitor (in Hz)
} GLFWvidmode;

CMake really doesn't like when you move a file with the cache still in the last file
Just delete the cache and do it all again.
cmake -B build -S . -G "Ninja" for personal machine desk/laptop

### Template Declarations with SFINAE 
In Vector, have to make sure that the cross product has to share declaration, using SFINAE, to change the return type.

Have we done enough edge case checking? 
 

### Static Libs - With Templates
For instantiation - these files cannot be in a static lib, definition needs to be visible when instantiation. 

Making this a static lib - would be interesting - requires: 
Explicit Instantiation - this would be in the Vector.cpp - still deciding on this

The other option is having a header only library - really enticing - much simpler and portable to my other projects. 

## Documentation 
Doxygen
 

## Matrix
https://glm.g-truc.net/0.9.4/api/a00133.html

There is the idea of having the template, generic size class, that I will continue working with. 
For faster implementation, I will also have a Mat4 class, in tandem with helper functions to create rotation, scale and transform etc. 

Matrix Multiplication - Dot product of every row WITH every column
which is the sum of products per row - per column
rows of left hand matrix (first matrix) - columns of the right (second matrix)
 
operator*(Mat4 const& other)
{ 
   Mat4<float> result;
   for(int i = 0; i < 4; ++i)
   { 
      for(tin j = 0; j < 4; ++i)
      { 
         result._data[i][j] = 0
         for(int k = 0; k < 4; ++i)
         { 
            result._data[i][j] += _data [i][k] * other_data[k][j];
         }
      }
   }

   return result;
}

O(n^3)
 
TODO - Research Schlassens

We can avoid rotation matrices by using Quaternions which is also a better challenge


## Quaternions
Requiring a reasonable interface from vectors: 
v' = qvq{-1}

Trying to avoid a class to keep things lightweight - doesn't seem necessary

As self contained as possible
 
Rotating a Point using Quaternions
https://danceswithcode.net/engineeringnotes/quaternions/quaternions.html

args as degrees than convert, remedy later
my brain works better in degrees

Potentially convert quaternion to matrix
Active rotation - rotating object (q{-1} * v) * q
Passive rotation - rotating coordinate space (q * v) * q{-1}

radians -> pi / 180 (pi per 180 deg)
 
The reflection of a vector requires a reference - I'm not convinced this the right thing to do
 
Upon working implementation, had errors in results that should be 0, being at xe-8. 
Due to floating point inaccuracies, that are found (I believe) in std::sin/cos
Therefore, number will be rounded to at the end fo the function in order to avoid these small inaccuracies. 
