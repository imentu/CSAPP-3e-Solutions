#include <stdio.h>
#include <assert.h>
#include <limits.h>

/* 
    将 3 * x / 4 变换为 (a + b) * 3 / 4。
    其中 a 是 x 的高 30 位，b 是x的低 2 位。
    这样 a 只需先除 4 再乘 3 即可避免溢出，且该部分不需要处理舍入。
    b 按正常补码除法进行运算并处理舍入。
    将结果相加即可得到答案。
*/
int threeforths(int x)
{
    int a = x & ~0x3;
    int b = x & 0x3;

    int ad4 = a >> 2;
    int ad4m3 = (ad4 << 1) + ad4;

    int bm3 = (b << 1) + b;
    (x & INT_MIN) && (bm3 += 3);
    int bm3d4 = bm3 >> 2;

    return ad4m3 + bm3d4;
}

int main(int argc, char *argv[])
{
    assert(threeforths(8) == 6);
    assert(threeforths(9) == 6);
    assert(threeforths(10) == 7);
    assert(threeforths(11) == 8);
    assert(threeforths(12) == 9);

    assert(threeforths(-8) == -6);
    assert(threeforths(-9) == -6);
    assert(threeforths(-10) == -7);
    assert(threeforths(-11) == -8);
    assert(threeforths(-12) == -9);
    return 0;
}