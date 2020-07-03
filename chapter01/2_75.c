#include <stdio.h>
#include <assert.h>
#include <inttypes.h>

int signed_high_prod(int x, int y)
{
    int64_t mul = (int64_t)x * y;
    return mul >> 32;
}

/*
    (x' * y') / 2^w = [(x + x_sign * 2^w)(y + y_sign * 2^w)] / 2^w
                    = [x * y + x * y_sign * 2^w + y * x_sign * 2^w + x_sign * y_sign * 2^(2 * w)] / 2^w
                    = (x * y) / 2^w + x * y_sign + y * x_sign                            // x_sign * y_sign * 2^(2 * w) 超出64位表示范围，可消去。
*/
unsigned unsigned_high_prod(unsigned x, unsigned y)
{
    int x_sign = x >> 31;
    int y_sign = y >> 31;

    int signed_prod = signed_high_prod(x, y);

    return signed_prod + x * y_sign + y * x_sign;
}

/* a theorically correct version to test unsigned_high_prod func */
unsigned another_unsigned_high_prod(unsigned x, unsigned y)
{
    uint64_t mul = (uint64_t)x * y;
    return mul >> 32;
}

int main(int argc, char *argv[])
{
    unsigned x = 0x12345678;
    unsigned y = 0xFFFFFFFF;

    assert(another_unsigned_high_prod(x, y) == unsigned_high_prod(x, y));
    return 0;
}