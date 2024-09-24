#include "FluidSimulator.h"
#include "SPHKernel.h"

//https://pysph.readthedocs.io/en/latest/reference/equations.html#
//I love physics

FluidSimulator::FluidSimulator(float restDensity, float stiffness, float viscosity, float timeStep)
    : restDensity(restDensity), stiffness(stiffness), viscosity(viscosity), timeStep(timeStep) {}

void FluidSimulator::addParticle(const Particle &particle)
{
    particles.push_back(particle);
}

void FluidSimulator::computeDensityPressure()
{
    for (size_t i = 0; i < particles.size(); ++i)
    {
        float density_sum = 0.0f;
        for (size_t j = 0; j < particles.size(); ++j)
        {
            float r = (particles[i].position - particles[j].position).norm();
            density_sum += SPHKernel::poly6(r, 1.0f);
        }
        particles[i].density = density_sum;
        particles[i].pressure = particles[i].density - restDensity;
    }
}

void FluidSimulator::computeForces()
{
    for (size_t i = 0; i < particles.size(); ++i)
    {
        Eigen::Vector3f force = Eigen::Vector3f::Zero();
        for (size_t j = 0; j < particles.size(); ++j)
        {
            if (i == j)
                continue;
            Eigen::Vector3f direction = particles[i].position - particles[j].position;
            float r = direction.norm();
            direction.normalize();
            force += -direction * (particles[i].pressure + particles[j].pressure) * SPHKernel::spiky(r, 1.0f);
        }
        particles[i].acceleration = force / particles[i].density;
    }
}

void FluidSimulator::step()
{
    for (Particle &particle : particles)
    {
        particle.velocity += particle.acceleration * timeStep;
        particle.position += particle.velocity * timeStep;
    }
}

const std::vector<Particle> &FluidSimulator::getParticles() const
{
    return particles;
}
