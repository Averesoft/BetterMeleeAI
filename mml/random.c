#include "error.h"
#include "random.h"
#include "native_functions.h"
#include "gctypes.h"

#ifdef PAL

#error random.c not compatible with PAL

#else

static volatile u32* randSeed = (u32*) 0x804d5f90;

#endif

float rand(void)
{
    u32 (*rng)(u32) = RAND_INT_FPTR;
    rng(2); //reset seed
    return (float) *randSeed / (u32) 0xffffffff;
}

float uniform(float a, float b)
{
    return rand() * (b - a) + a;
}

unsigned sample(const float* probs, size_t size)
{
    float unif = rand();
    float total = 0.0;
    for (unsigned i = 0; i < size; ++i)
    {
        total += probs[i];
        if (unif < total) { return i;}
    }
    THROW_ERROR(0, "invalid probabilities");
    return 0;
}

bool chance(FunctionArg prob)
{
    return rand() < prob.f;
}

