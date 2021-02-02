
#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>

#include "callBacks.hpp"

void monitor_callback (GLFWmonitor* monitor, int event)
{
    if (event == GLFW_CONNECTED)
    {
        fprintf(stdout,"The monitor was connected");
    }
    if (event == GLFW_DISCONNECTED)
    {
        fprintf(stdout,"The monitor was disconnected");
    }
} 
