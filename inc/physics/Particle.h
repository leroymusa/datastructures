#ifndef PARTICLE_H
#define PARTICLE_H

#include <Eigen/Dense>

class Particle
{
public:
    Particle(const Eigen::Vector3f &position);
    Eigen::Vector3f position;
    Eigen::Vector3f velocity;
    Eigen::Vector3f acceleration;
    float mass;
    float density;
    float pressure;
};

#endif /* PARTICLE_H */
