#ifndef SPHKERNEL_H
#define SPHKERNEL_H

class SPHKernel
{
public:
    static float poly6(float r, float h);
    static float spiky(float r, float h);
};

#endif /* SPHKERNEL_H */
