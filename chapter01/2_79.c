#include <stdio.h>
#include <assert.h>
#include <limits.h>

/*
    2_78中实现的 x / 2^k 函数。
*/
int divide_power2(int x, int k)
{
    int is_neg = x & INT_MIN;
    (is_neg && (x = x + (1 << k) - 1));
    return x >> k;
}

int mul3div4(int x)
{
    int mul3 = (x << 1) + x;
    return divide_power2(mul3, 2);
}

int main(int argc, char *argv[])
{
    int x = 0x87654321;
    assert(mul3div4(x) == x * 3 / 4);
    return 0;
}