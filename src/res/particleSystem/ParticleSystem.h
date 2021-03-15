#ifndef PARTICLE_SYSTEM_INCLUDED
#define PARTICLE_SYSTEM_INCLUDED

#include <stdio.h>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glut.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/compatibility.hpp>

#include "../shaders/shader.h"
#include "../Random.h"
using namespace glm;

struct ParticleProps 
{
    vec2 Position;
    vec2 Velocity,VelocityVariation;
    vec4 Color;
    float LifeTime;
    float SizeBegin,SizeEnd,SizeVariation;

    ParticleProps()
    {};
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

    Particle()
    {};

    };

    int oldTimeSinceStart = 0;
    std::vector<Particle> particlePool;
    unsigned int poolIndex = 99;
    unsigned int ParticleShaderTransform,ParticleShaderColor;
    unsigned int ParticleVA;

 public:
    ParticleSystem();
    void Update();
    void InitializeShader(Shader& shader);
    void Emit (const ParticleProps& particleProps);
    void Draw();
    float ElapsedTime();

};

#endif
