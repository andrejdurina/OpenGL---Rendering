#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Mouse.h"

int Mouse::mousePointer (GLFWwindow* window)
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

    COORD mpos;
    glfwSetCursor(window,glfwCreateCursor(&image,0,0));

    glfwGetCursorPos(window,&mpos.X,&mpos.Y);
    printf("X : %d \n Y: %d",mpos.X,mpos.Y);
    glLoadIdentity();
    glTranslatef(mpos.X,mpos.Y,0);

    return 1;
}
