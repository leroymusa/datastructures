#ifndef FLUIDSIMULATOR_H
#define FLUIDSIMULATOR_H

#include <vector>
#include "Particle.h"

class FluidSimulator
{
public:
    FluidSimulator(float restDensity, float stiffness, float viscosity, float timeStep);
    void addParticle(const Particle &particle);
    void computeDensityPressure();
    void computeForces();
    void step();
    const std::vector<Particle> &getParticles() const;

private:
    std::vector<Particle> particles;
    float restDensity;
    float stiffness;
    float viscosity;
    float timeStep;
};

#endif /* FLUIDSIMULATOR_H */
