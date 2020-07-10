#include <stdio.h>
#include <assert.h>

typedef unsigned float_bits;

float u2f(unsigned x)
{
    return *(float *)&x;
}

unsigned f2u(float x)
{
    return *(unsigned *)&x;
}

float_bits float_absval(float_bits f)
{
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    if (exp == 0xFF && frac != 0)
    {
        return f;
    }
    /*
        符号位置 0 即可。
        但在我的机器上 |-0.0| = -0.0
    */
    return f & ((unsigned)-1 >> 1);
}

int main(int argc, char const *argv[])
{
    for (unsigned i = 0; i != ~0; i++)
    {
        float x = u2f(i);
        x = x < 0 ? -x : x;
        float r = u2f(float_absval(i));
        if (f2u(r) != f2u(x))
        {
            /*
                NAN != NAN
            */
            printf("bits:%08X x:%f r:%f x_bits:%08X r_bits:%08X\n", i, x, r, f2u(x), f2u(r));
            break;
        }
        if (i % 1000000000 == 0 && i != 0)
        {
            printf("tested %d numbers\n", i);
        }
    }
    return 0;
}
