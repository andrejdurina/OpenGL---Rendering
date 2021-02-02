#include "ParticleSystem.h"

#include "src/math/math.hpp"

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