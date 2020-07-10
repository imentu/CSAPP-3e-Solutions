#include <stdio.h>
#include <assert.h>

/*
    无符号右移，将移动过的位置为0即可。
*/
unsigned srl(unsigned x, int k)
{
    unsigned xsra = (int)x >> k;
    int w = sizeof(int) << 3;
    unsigned mask = ~(-1 << w - k);
    return xsra & mask;
}

/*
    测试符号位，若符号位为 1，则生成掩码将 xsrl 移动过的位置位为 1；若符号位为 0，则掩码设置为 0。

    !0 = 1;
    1 - 1 = 0x00000000;
    !1 = 0;
    0 - 1 = 0xFFFFFFFF;
*/
int sra(int x, int k)
{
    int xsrl = (unsigned)x >> k;
    int w = sizeof(int) << 3;
    int sign = 1 << w - 1;
    sign &= x;
    int mask = (!sign - 1) << w - k;
    return xsrl | mask;
}

int main(int argc, char *argv[])
{
    unsigned test_unsigned = 0x12345678;
    int test_int = 0x12345678;

    assert(srl(test_unsigned, 4) == test_unsigned >> 4);
    assert(sra(test_int, 4) == test_int >> 4);

    test_unsigned = 0x87654321;
    test_int = 0x87654321;

    assert(srl(test_unsigned, 4) == test_unsigned >> 4);
    assert(sra(test_int, 4) == test_int >> 4);

    return 0;
}