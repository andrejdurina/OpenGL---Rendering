#include <stdio.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

using namespace glm;

class Geometry
{

private:
    unsigned int rectangleindices[6] = {
    0, 1, 2, 2, 3, 0};

public:
    float *createRectangle(float x0, float y0, float x1, float y1);
    inline unsigned int* GetRectangleIndices(){return rectangleindices;};
};
