#include <stdio.h>
#include <assert.h>
#include <math.h>

float u2f(unsigned x)
{
    return *(float *)&x;
}

/* 2^x */
float fpwr2(int x)
{
    /* Result exponent and fraction */
    unsigned exp, frac;
    unsigned u;

    /*
        非规格化数仅最低位为 1 时表示的数最小，为 2^-148。
        规格化数 M = 1 + frac，若要表示 2^x 小数部分只能为 0。所以规格化数最低只能表示 2^-126。
        注意处理规格化数的偏置即可。
    */
    if (x < -149)
    {
        /* too small. return 0.0 */
        exp = 0;
        frac = 0;
    }
    else if (x < -126)
    {
        /* Denormalized result */
        exp = 0;
        frac = 1 >> (-126 - x);
    }
    else if (x < 128)
    {
        /* Normalized result */
        exp = x + 127;
        frac = 0;
    }
    else
    {
        /* Too big, return +oo */
        exp = 0xFF;
        frac = 0;
    }

    /* pack exp and frac into 32 bits */
    u = exp << 23 | frac;
    /* Result as float */
    return u2f(u);
}

int main(int argc, char *argv[])
{
    assert(fpwr2(0) == powf(2, 0));
    assert(fpwr2(100) == powf(2, 100));
    assert(fpwr2(-100) == powf(2, -100));
    assert(fpwr2(10000) == powf(2, 10000));
    assert(fpwr2(-10000) == powf(2, -10000));
    return 0;
}