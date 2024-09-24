#include <iostream>
#include <vector>
#include <Eigen/Dense>
#include <cmath>

const float H = 0.0457f;
const float REST_DENSITY = 1000.0f;
const float GAS_CONSTANT = 2000.0f;
const float VISCOSITY = 0.01f;
const float MASS = 0.02f;
const float TIME_STEP = 0.01f;
const Eigen::Vector3f GRAVITY(0.0f, -9.81f, 0.0f);

class SPHKernel
{
public:
    float poly6(const Eigen::Vector3f &r) const
    {
        float r_len = r.norm();
        if (r_len > H)
            return 0.0f;
        float diff = H * H - r_len * r_len;
        return 315.0f / (64.0f * M_PI * pow(H, 9)) * pow(diff, 3);
    }

    Eigen::Vector3f spikyGrad(const Eigen::Vector3f &r) const
    {
        float r_len = r.norm();
        if (r_len > H || r_len == 0)
            return Eigen::Vector3f(0, 0, 0);
        float diff = H - r_len;
        return -45.0f / (M_PI * pow(H, 6)) * diff * diff * (r / r_len);
    }

    float viscosityLaplacian(const Eigen::Vector3f &r) const
    {
        float r_len = r.norm();
        if (r_len > H)
            return 0.0f;
        return 45.0f / (M_PI * pow(H, 6)) * (H - r_len);
    }
};

class Particle
{
public:
    Eigen::Vector3f position;
    Eigen::Vector3f velocity;
    Eigen::Vector3f force;
    float density;
    float pressure;

    Particle(const Eigen::Vector3f &pos) : position(pos), velocity(0, 0, 0), force(0, 0, 0), density(0), pressure(0) {}
};

class FluidSimulator
{
private:
    std::vector<Particle> particles;
    SPHKernel kernel;

public:
    FluidSimulator() = default;

    void addParticle(const Eigen::Vector3f &position)
    {
        particles.emplace_back(Particle(position));
    }

    void computeDensityPressure()
    {
        for (auto &pi : particles)
        {
            pi.density = 0;
            for (const auto &pj : particles)
            {
                Eigen::Vector3f r = pi.position - pj.position;
                pi.density += MASS * kernel.poly6(r);
            }
            pi.pressure = GAS_CONSTANT * (pi.density - REST_DENSITY);
        }
    }

    void computeForces()
    {
        for (auto &pi : particles)
        {
            Eigen::Vector3f pressure_force(0, 0, 0);
            Eigen::Vector3f viscosity_force(0, 0, 0);

            for (const auto &pj : particles)
            {
                if (&pi == &pj)
                    continue;

                Eigen::Vector3f r = pi.position - pj.position;
                float distance = r.norm();

                if (distance < H)
                {

                    pressure_force += -MASS * (pi.pressure + pj.pressure) / (2.0f * pj.density) * kernel.spikyGrad(r);

                    viscosity_force += VISCOSITY * MASS * (pj.velocity - pi.velocity) / pj.density * kernel.viscosityLaplacian(r);
                }
            }

            pi.force = pressure_force + viscosity_force + pi.density * GRAVITY;
        }
    }

    void integrate()
    {
        for (auto &p : particles)
        {

            p.velocity += TIME_STEP * p.force / p.density;
            p.position += TIME_STEP * p.velocity;

            if (p.position.y() < 0.0f)
            {
                p.position.y() = 0.0f;
                p.velocity.y() = 0.0f;
            }
        }
    }

    void step()
    {
        computeDensityPressure();
        computeForces();
        integrate();
    }

    const std::vector<Particle> &getParticles() const
    {
        return particles;
    }
};