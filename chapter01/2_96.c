#include <stdio.h>
#include <assert.h>

typedef unsigned float_bits;

float u2f(unsigned x)
{
    return *(float *)&x;
}

int float_f2i(float_bits uf)
{
    unsigned sig = uf >> 31;
    unsigned exp = uf >> 23 & 0xFF;
    unsigned frac = uf & 0x7FFFFF;
    unsigned bias = 0x7F;

    int num;
    unsigned E;
    unsigned M;

    /*
   * consider positive numbers
   *
   * 0 00000000 00000000000000000000000
   *   ===>
   * 0 01111111 00000000000000000000000
   *   0 <= f < 1
   * get integer 0
   *
   * 0 01111111 00000000000000000000000
   *   ===>
   * 0 (01111111+31) 00000000000000000000000
   *   1 <= f < 2^31
   * integer round to 0
   *
   * 0 (01111111+31) 00000000000000000000000
   *   ===>
   * greater
   *   2^31 <= f < oo
   * return 0x80000000
   */
    if (exp >= 0 && exp < 0 + bias) // 小于 1 时，舍入为 0。
    {
        num = 0;
    }
    else if (exp >= 31 + bias) // 溢出
    {
        num = 0x80000000;
    }
    else
    {
        E = exp - bias;
        M = frac | 0x800000; // frac + 1
        if (E > 23)
        {
            num = M << (E - 23); // (frac + 1) * 2^n
        }
        else
        {
            num = M >> (23 - E); // 左移不完小数位时，向零舍入。
        }
    }

    return sig ? -num : num;
}

int main(int argc, char const *argv[])
{
    for (unsigned i = 0; i != ~0; i++)
    {
        int x = (int)u2f(i);
        int r = float_f2i(i);
        if (r != x)
        {
            printf("bits:%08X x:%d r:%d x_bits:%08X r_bits:%08X\n", i, x, r, x, r);
            break;
        }
        if (i % 1000000000 == 0 && i != 0)
        {
            printf("tested %ld numbers\n", (long)i);
        }
    }
    return 0;
}
