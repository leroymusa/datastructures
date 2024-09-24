#include "SPHKernel.h"
#include <cmath>

float SPHKernel::poly6(float r, float h)
{
    float result = 0.0f;
    if (r >= 0 && r <= h)
    {
        float factor = (h * h) - (r * r);
        result = (315.0f / (64.0f * M_PI * std::pow(h, 9))) * std::pow(factor, 3);
    }
    return result;
}

float SPHKernel::spiky(float r, float h)
{
    float result = 0.0f;
    if (r >= 0 && r <= h)
    {
        float factor = h - r;
        result = (15.0f / (M_PI * std::pow(h, 6))) * std::pow(factor, 3);
    }
    return result;
}
