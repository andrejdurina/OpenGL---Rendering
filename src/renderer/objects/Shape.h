#ifndef GENERATE_OBJECT_INCLUDE
#define GENERATE_OBJECT_INCLUDE

#include <stdio.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

using namespace glm;

class Geometry
{


private:
    unsigned int objectindices[6] = {
    0, 1, 2, 2, 3, 0};
    unsigned int objectCount = 0;

public:
    float *createObject(float x0, float y0, float x1, float y1);
    inline unsigned int* GetIndices(){return objectindices;};
    void SetCount(){objectCount += 1;};
    void ResetCount(){objectCount = 0;};
    inline unsigned int GetCount(){return objectCount;}

};
#endif