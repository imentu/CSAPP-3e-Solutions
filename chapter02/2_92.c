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

/*
    提取 exp 和 frac 部分，若 exp 二进制全为 1 且 frac != 0，则 f 为 NAN，返回 f。
    其它情况至于反置符号位即可。
*/
float_bits float_negate(float_bits f)
{
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    if (exp == 0xFF && frac != 0)
    {
        return f;
    }
    return f ^ (1 << 31);
}

int main(int argc, char const *argv[])
{
    for (unsigned i = 0; i != ~0; i++)
    {
        float x = u2f(i);
        float r = u2f(float_negate(i));
        if (f2u(r) != f2u(-x))
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
