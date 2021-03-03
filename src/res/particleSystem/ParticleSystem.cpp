#include "ParticleSystem.h"

#include "src/testFuncs/math.h"

#include <glm/gtc/constants.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/compatibility.hpp>

ParticleSystem :: ParticleSystem()
{
    particlePool.resize(500);
}

void ParticleSystem::OnUpdate()
{

}