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

float_bits float_half(float_bits f)
{
    unsigned sig = f >> 31;
    unsigned rest = f & 0x7FFFFFFF;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    int is_NAN_or_oo = (exp == 0xFF);
    if (is_NAN_or_oo)
    {
        return f;
    }

    /*
        处理向偶数舍入，仅关心后两位即可
   
        00 => 0 只需 >>1
        01 => 0 只需 >>1
        10 => 1 只需 >>1
        11 => 1 + 1 右移并加一
   */
    int addition = (frac & 0x3) == 0x3;

    if (exp == 0)
    {
        /* 非规格化 */
        frac >>= 1;
        frac += addition;
    }
    else if (exp == 1)
    {
        /* 非规格化到规格化过渡 */
        rest >>= 1;
        rest += addition;
        exp = rest >> 23 & 0xFF;
        frac = rest & 0x7FFFFF;
    }
    else
    {
        /* 规格化数 */
        exp -= 1;
    }

    return sig << 31 | exp << 23 | frac;
}

int main(int argc, char const *argv[])
{
    for (unsigned i = 0; i != ~0; i++)
    {
        float x = u2f(i);
        x = x * 0.5;
        float r = u2f(float_half(i));
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
