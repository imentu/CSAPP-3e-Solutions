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

float_bits float_twice(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    /*
        f == ±∞ 或 f == NAN
    */
    if (exp == 0xFF)
    {
        return f;
    }
    /*
        规格化值 
    */
    if (exp == 0)
    {
        frac <<= 1;
    }
    else if (exp == 0xFF - 1) // 非规格化，乘 2 溢出
    {
        exp = 0xFF;
        frac = 0;
    }
    else
    {
        exp += 1;
    }
    return sign << 31 | exp << 23 | frac;
}

int main(int argc, char const *argv[])
{
    for (unsigned i = 0; i != ~0; i++)
    {
        float x = u2f(i);
        x = x * 2.0;
        float r = u2f(float_twice(i));
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
