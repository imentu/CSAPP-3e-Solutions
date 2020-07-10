#include <stdio.h>
#include <assert.h>

/*
    设置所有低 n 位为 1。

    将全 1 二进制位右移 w - n 位即可。
*/
int lower_one_mask(int n)
{
    int w = sizeof(int) << 3;
    return (unsigned)-1 >> (w - n);
}

int main(int argc, char *argv[])
{
    assert(lower_one_mask(6) == 0x3F);
    assert(lower_one_mask(17) == 0x1FFFF);
    assert(lower_one_mask(32) == 0xFFFFFFFF);
    return 0;
}