#ifndef MOUSE_INCLUDED
#define MOUSE_INCLUDED

#include <GLFW/glfw3.h>

class Mouse 
{
    public:
    int mousePointer (GLFWwindow* window);

    typedef struct COORD {
        double X;
        double Y;
    } COORD;

};
#endif