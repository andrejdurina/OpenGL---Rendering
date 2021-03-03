#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "particles.h"
#include <glm/glm.hpp>

using namespace glm;

struct Particle {
    vec2 Position,Velocity;
    vec4 Color;
    float Life;

    Particle()
    : Position(0.0f), Velocity(0.0f), Color(1.0f), Life(0.0f) {}
};

void draw_mouse_pointer(){
    
}
/* 

    unsigned int dt=1;
    unsigned int particles_count = 35;
    std::vector<Particle> particles;

    for ( unsigned int i = 0; i < particles_count; ++i)
    {
        particles.push_back(Particle());
    }

    unsigned int new_particles_count = 5;

    for(unsigned int i=0; i < new_particles_count; ++i){

        int unusedParticle = FirstUnusedParticle();
        RespawnParticle(particles[unusedParticle],object,offset);
    }

    for (unsigned int i = 0; i < particles_count; ++i){

        Particle &p = particles[i];
        p.Life -= dt;
        if(p.Life > 0.0f)
        {
            p.Position -= p.Velocity * dt;
            p.Color.a -= dt * 2.5f;
        }
    }
    
}

unsigned int FirstUnusedParticle(){

    unsigned int lastUsedParticle = 0;
    for ( unsigned int i = lastUsedParticle ; i < particles_count; ++i){
        if (particles[i].Life <= 0.0f)
        {
            lastUsedParticle = i;
            return i;
        }
    }
    lastUsedParticle = 0;
    return 0 */