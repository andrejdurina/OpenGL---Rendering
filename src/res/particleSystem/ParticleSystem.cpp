#include "ParticleSystem.h"
#include <glm/gtc/constants.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/compatibility.hpp>

ParticleSystem::ParticleSystem()
{
    particlePool.resize(100);
}

void ParticleSystem::Update()
{   
    float ts = ElapsedTime();
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
void ParticleSystem::Initialize(Shader& shader)
{

    glCreateVertexArrays(1,&ParticleVA);
    glBindVertexArray(ParticleVA);

    unsigned int ParticleVB,ParticleIB;
    glCreateBuffers(1,&ParticleVB);
    glBindBuffer(GL_ARRAY_BUFFER, ParticleVB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);

    glEnableVertexArrayAttrib(ParticleVB,0);
    glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,2*sizeof(float),0);

    glCreateBuffers(1,&ParticleIB);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ParticleIB);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices),indices,GL_STATIC_DRAW);

		ParticleShaderTransform = glGetUniformLocation(shader.GetID(), "u_Transform");
		ParticleShaderColor = glGetUniformLocation(shader.GetID(), "u_Color");

        shader.Bind();

}   

void ParticleSystem::Draw()
{

	for (auto& particle : particlePool)
	{
		if (!particle.Active)
			continue;

		// Fade away particles
		float life = particle.LifeRemaining / particle.LifeTime;
		glm::vec4 color = glm::vec4(255.0,255.0,255.0, life);

		float size = glm::lerp(particle.SizeEnd, particle.SizeBegin, life);
		
		glm::mat4 transform = glm::translate(glm::mat4(1.0f), { particle.Position.x, particle.Position.y, 0.0f })
			* glm::rotate(glm::mat4(1.0f), particle.Rotation, { 0.0f, 0.0f, 1.0f })
			* glm::scale(glm::mat4(1.0f), { size, size, 1.0f });
		glUniformMatrix4fv(ParticleShaderTransform, 1, GL_FALSE, glm::value_ptr(transform));
		glUniform4fv(ParticleShaderColor, 1, glm::value_ptr(color));
		glBindVertexArray(ParticleVA);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	}
}
void ParticleSystem::Emit(const ParticleProps &particleProps)
{
    Particle& particle = particlePool[poolIndex];
    particle.Active = true;
    particle.Position = particleProps.Position;
    particle.Rotation = Random::Float() *2.0f*glm::pi<float>();

    particle.Velocity - particleProps.Velocity;
    particle.Velocity.x += particleProps.VelocityVariation.x * (Random::Float() );
    particle.Velocity.y += particleProps.VelocityVariation.y * (Random::Float() );

    particle.Color = particleProps.Color;

    particle.LifeTime = particleProps.LifeTime;
    particle.LifeRemaining = particleProps.LifeTime;
    particle.SizeBegin = particleProps.SizeBegin + particleProps.SizeVariation * (Random::Float());
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