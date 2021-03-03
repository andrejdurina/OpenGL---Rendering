#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>


#include "particles.h"
#include <glm/glm.hpp>

using namespace glm;

struct ParticleProps 
{
    vec2 Position;
    vec2 Velocity,VelocityVariation;
    vec4 Color;
    float LifeTime;

};

class ParticleSystem
{
 public:
    ParticleSystem();
    void OnUpdate();
    void OnRender();

    void Emit (const ParticleProps& particleProps);

    timespec elapsedTime(){
        static double limitFPS = 1.0 / 60.0;
        double lastTime = glfwGetTime(), timer = lastTime;
        double deltaTIme = 0, nowTime= 0;
        int frames = 0 , updates = 0;

    };
    private:
    struct Particle 
    {
        vec2 Position;
        vec2 Velocity;
        vec4 Color;
        float LifeTime = 1.0f;
        float LifeRemaining = 0.0f;
        bool Active = false;
    };

    std::vector<Particle> particlePool;
    unsigned int poolIndex = 499;

};
