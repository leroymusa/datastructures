#include "physics/FluidSimulator.h"
#include "physics/Particle.h"
#include "physics/SPHKernel.h"

#include <gtest/gtest.h>
#include <Eigen/Dense>

TEST(SPHFluidTest, IntegrationStep)
{
    FluidSimulator simulator(1000.0f, 3.0f, 0.1f, 0.01f);
    simulator.addParticle(Particle(Eigen::Vector3f(0.0f, 0.0f, 0.0f)));
    simulator.addParticle(Particle(Eigen::Vector3f(0.5f, 0.5f, 0.5f)));

    simulator.computeDensityPressure();
    simulator.computeForces();

    Eigen::Vector3f initialPosition = simulator.getParticles()[0].position;
    simulator.step();

    EXPECT_NE(simulator.getParticles()[0].position, initialPosition);
}