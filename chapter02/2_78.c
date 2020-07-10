#include <stdio.h>
#include <assert.h>
#include <limits.h>

/*
    若 x 小于 0，则通过增加偏置实现向 0 舍入。
    P73 有详细推导。
*/
int divide_power2(int x, int k)
{
    (!!(x & INT_MIN)) && (x = (x + (1 << k) - 1));
    return x >> k;
}

int main(int argc, char *argv[])
{
    int x = 0x80000007;
    assert(divide_power2(x, 1) == x / 2);
    assert(divide_power2(x, 2) == x / 4);
    return 0;
}