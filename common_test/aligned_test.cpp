#include <iostream>

class Vec3
{
    float x, y, z;
    float w __attribute__((unused));
} __attribute__((aligned(16)));

typedef union __attribute__((aligned(16))) FVec
{
    __attribute__((aligned(16))) struct
    {
        float vx, vy, vz, vw;
    };
    __attribute__((aligned(16))) struct
    {
        int ix, iy, iz, iw;
    };
    float f[4];
} FVec;

void Test1(FVec *fvec)
{
    printf("x:%f y:%f z:%f w:%f \n", fvec->vx, fvec->vy, fvec->vz, fvec->vw);
}

void Run()
{
}