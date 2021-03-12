#include "Random.h"

    static std::mt19937 randomEngine;
    static std::uniform_int_distribution<std::mt19937::result_type> distribution;
 