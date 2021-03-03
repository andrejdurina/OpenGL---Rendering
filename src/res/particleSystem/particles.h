#ifndef PARTICLES_INCLUDED
#define PARTICLES_INCLUDED
#include <GLFW/glfw3.h>

typedef struct POINT
{
    double x;
    double y;
} POINT;

void draw_mouse_pointer();
int mousePointer(GLFWwindow* window);

#endif
