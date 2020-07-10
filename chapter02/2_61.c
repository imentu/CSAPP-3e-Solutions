#include <stdio.h>
#include <assert.h>

/*
    x = 0时，!x == 1。
    x = -1时，!(~x) == 1。
    x最低有效字节的位都等于1时，!(x ^ 0xFF) == 1。
    x最高有效字节的位都等于0时，!(x & (0xFF << ((sizeof(int) - 1) << 3)))== 1。 将掩码最高有效字节设为0xFF与x相与，若 x = 0，则结果为 0，逻辑取反后返回 1。
*/
#define expression(x) ((!x) || !(~x) || !(x ^ 0xFF) || !(x & (0xFF << ((sizeof(int) - 1) << 3))))

int main(int argc, char *argv[])
{
    int all_bit_one = ~0;
    int all_bit_zero = 0;

    assert(expression(all_bit_one));
    assert(expression(all_bit_zero));
    assert(expression(0x1234ff));
    assert(expression(0x1234));

    assert(!expression(0xFF123400));
    return 0;
}