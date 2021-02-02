#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include "math.hpp"

using namespace glm;

//This method transforms x,y begin & x,y end coordinates to percentage values of OpenGL.
float* transformCoord(GLint *viewport, Pixels *COORDs)
{
    //Data check, if in viewport bound
    if (COORDs->start_x > viewport[2] || COORDs->start_y > viewport[3] || COORDs->start_x < viewport[0] || COORDs->start_y < viewport[1] || COORDs->end_x < viewport[0] || COORDs->end_y < viewport[1] || COORDs->end_x > viewport[2] || COORDs->end_y > viewport[3])
    {
        fprintf(stderr, "\nCoordinate out of viewport boundings");
        exit(1);
    }

    int vp_width_half = viewport[2] / 2;
    int vp_height_half = viewport[3] / 2;
    float *math_buffer_data ;
    math_buffer_data = new float [7] ;

     //Load coordinates for drawn rectangle.
    math_buffer_data[0] = COORDs->start_x;
    math_buffer_data[1] = COORDs->start_y;
    math_buffer_data[2] = COORDs->start_x;
    math_buffer_data[3] = COORDs->end_y;
    math_buffer_data[4] = COORDs->end_x;
    math_buffer_data[5] = COORDs->end_y;
    math_buffer_data[6] = COORDs->end_x;
    math_buffer_data[7] = COORDs->start_y; 

     // Update sign.
    for (int i = 0; i < 8; i += 2)
    {
        if (math_buffer_data[i] < vp_width_half)
        {
            math_buffer_data[i]  =  -viewport[2] + math_buffer_data[i];
        }
        if (math_buffer_data[i+1] < vp_height_half)
        {
            math_buffer_data[i+1] =  -viewport[3] + math_buffer_data[i+1];
        } 
          if (math_buffer_data[i] == vp_width_half)
        {
            math_buffer_data[i]  =  -vp_width_half+ math_buffer_data[i];
        }
        if (math_buffer_data[i+1] == vp_height_half)
        {
            math_buffer_data[i+1] =  -vp_height_half + math_buffer_data[i+1];
        } 
    }
    // Convert the pixels values to percentage for OpenGL
    for (int i = 0; i < 8 ; i ++)
    {
        if(i % 2 == 0 || i == 0)
        {
            math_buffer_data[i] /= viewport[2];
        }
        else {
            math_buffer_data[i] /= viewport[3];
        }
    }
  
    return math_buffer_data;
    delete math_buffer_data;
}

vec3 hsv2rgb(vec3 source){
    float h = source.x;
    float s = source.y;
    float v = source.z;    

    float r,g,b;
    
    int hi = (int)(h/60.0f) % 6;
    float f = (h/ 60.0f) -hi;
    float p = v * ( 1.0f -s );
    float q = v * (1.0f - s * f );
    float t = v * (1.0f -s * ( 1.0f - f));

    switch (hi)
    {
    case 0:  r=v, g=t, b=p;  break;
    case 1:  r=q, g=v, b=p;  break;
    case 2:  r=p, g=v, b=t;  break;
    case 3:  r=p, g=q, b=v;  break;
    case 4:  r=t, g=p, b=v;  break;
    case 5:  r=v, g=p, b=q;  break;
    }
       
    return vec3(r,g,b);
}

vec4 randomNum(){
    
    srand(static_cast <unsigned> (time(0)));
    vec4 color;
    for( int i = 0 ; i < 3 ; i++){
           color.x= static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
           color.y= static_cast <float> (rand()) / static_cast <float> (RAND_MAX);;
           color.z= static_cast <float> (rand()) / static_cast <float> (RAND_MAX);;
           color.w;
        }
    color.w = 1.0f;
    return color;
}

timer_t createTimer(int signal)
{
    struct sigevent event;
    event.sigev_notify=SIGEV_SIGNAL;
    event.sigev_signo = signal;

    timer_t timer;
    timer_create(CLOCK_REALTIME, &event, &timer);
    return (timer);
}

void startTimer(timer_t timer, int nsec, int nperiod)
{
    struct itimerspec time;
    time.it_value.tv_sec = 0;
    time.it_value.tv_nsec = nsec;
    time.it_interval.tv_sec = 0;
    time.it_interval.tv_nsec = nperiod;
    timer_settime(timer,CLOCK_REALTIME,&time,NULL);
}

void func(int number){

    fprintf(stdout,"Some text : %d \n",number);

}