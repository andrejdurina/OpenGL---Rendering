#include "ParticleSystem.h"
#include "Random.h"

#include <glm/gtc/constants.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/compatibility.hpp>

ParticleSystem::ParticleSystem()
{
    particlePool.resize(100);
}

void ParticleSystem::Update(float ts)
{
    for(auto& particle:particlePool)
    {
        if(!particle.Active)
            continue;
        
        if(particle.LifeRemaining <= 0.0f)
        {
            particle.Active = false;
            continue;
        }

        particle.LifeRemaining -= ts;
        particle.Position += particle.Velocity * ts;
        particle.Rotation += 0.02 * ts;
    }
}
void ParticleSystem::Initialize()
{

}

void ParticleSystem::Emit(const ParticleProps &particleProps)
{
    Particle& particle = particlePool[poolIndex];
    particle.Active = true;
    particle.Position = particleProps.Position;
    particle.Rotation = Random::Float() *2.0f*glm::pi<float>();

    particle.Velocity - particleProps.Velocity;
    particle.Velocity.x += particleProps.VelocityVariation.x * (Random::Float() - 0.5f);
    particle.Velocity.y += particleProps.VelocityVariation.y * (Random::Float() - 0.5f);

    particle.Color = particleProps.Color;

    particle.LifeTime = particleProps.LifeTime;
    particle.LifeRemaining = particleProps.LifeTime;
    particle.SizeBegin = particleProps.SizeBegin + particleProps.SizeVariation * (Random::Float()-0.5f);
    particle.SizeEnd = particleProps.SizeEnd;

    poolIndex = --poolIndex % particlePool.size();
}

float ParticleSystem::ElapsedTime()
{
    int timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
    int deltaTime = timeSinceStart - oldTimeSinceStart;
    oldTimeSinceStart = timeSinceStart;
    
    return deltaTime/1000;
}