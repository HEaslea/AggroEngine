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

