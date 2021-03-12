#include "Random.h"

float Random::Float()
    {  
       srand(static_cast<unsigned int>(clock()));
       return float(rand()) / (float(RAND_MAX) + 0.5);
    }
 