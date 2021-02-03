#ifndef MATH_HPP
#define MATH_HPP

struct Pixels {

    float start_x;
    float start_y;
    float end_x;
    float end_y;
    Pixels(float x0, float y0, float x1, float y1){
        this->start_x = x0;
        this->start_y = y0;
        this->end_x = x1;
        this->end_y = y1;
    };
};

float* transformRectangle(int *viewport, Pixels *COORDs);
glm::vec3 hsv2rgb(glm::vec3 source);
glm::vec4 randomNum();
timer_t createTimer(int signal);
void startTimer(timer_t timer, int nsec, int nperiod);
void func(int number);

#endif