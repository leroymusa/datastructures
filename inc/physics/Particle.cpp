#include "Particle.h"

Particle::Particle(const Eigen::Vector3f &position)
    : position(position),
      velocity(Eigen::Vector3f::Zero()),
      acceleration(Eigen::Vector3f::Zero()),
      mass(1.0f),
      density(0.0f),
      pressure(0.0f)
{
}
