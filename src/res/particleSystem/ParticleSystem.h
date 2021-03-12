#ifndef PARTICLE_SYSTEM_INCLUDED
#define PARTICLE_SYSTEM_INCLUDED

#include <stdio.h>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glut.h>

#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/gtx/compatibility.hpp>

using namespace glm;

struct ParticleProps 
{
    vec2 Position;
    vec2 Velocity,VelocityVariation;
    vec4 Color;
    float LifeTime;
    float SizeBegin,SizeEnd,SizeVariation;
};

class ParticleSystem
{
    
    private:
    struct Particle 
    {
        vec2 Position;
        vec2 Velocity;
        vec4 Color;
        float Rotation = 0.0f;
        float SizeBegin,SizeEnd;
        float LifeTime = 1.0f;
        float LifeRemaining = 0.0f;
        bool Active = false;
    };

    int oldTimeSinceStart = 0;
    std::vector<Particle> particlePool;
    unsigned int poolIndex = 99;
    uint ParticleShaderViewProj, ParticleShaderTransform,ParticleShaderColor;

 public:
    ParticleSystem();
    void Update(float ts);
    void Initialize();
    void Emit (const ParticleProps& particleProps);
    float ElapsedTime();

};

#endif
