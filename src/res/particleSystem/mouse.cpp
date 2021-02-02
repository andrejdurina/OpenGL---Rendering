#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "particles.hpp"

int mousePointer (GLFWwindow* window)
{   
    int width;
    int height;
    unsigned char pixels[15 * 15 * 2];
    memset(pixels,0xff,sizeof(pixels));
    GLFWimage image;
    image.width = 15;
    image.height = 15;
    image.pixels = pixels ;
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glfwGetWindowSize(window,&width,&height);
    glOrtho(0.0f,width,height,0.0f,-1.0f,1.0f);
    glMatrixMode(GL_MODELVIEW);

    POINT mpos;
    glfwSetCursor(window,glfwCreateCursor(&image,0,0));

    glfwGetCursorPos(window,&mpos.x,&mpos.y);

    glLoadIdentity();
    glTranslatef(mpos.x,mpos.y,0);

    draw_mouse_pointer();

    return 1;
}
