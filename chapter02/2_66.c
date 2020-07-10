#include <stdio.h>
#include <assert.h>

/*
    生成掩码表示x最左边的位。
    
    先用二分法将x变成0x0...011...1的位向量，然后将其右移一位加一即可。
    注意x = 0时，return 0。
*/
int leftmost_one(unsigned x)
{
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;

    return (x >> 1) + (x && 1);
}

int main(int argc, char const *argv[])
{
    assert(leftmost_one(0xFF00) == 0x8000);
    assert(leftmost_one(0x6000) == 0x4000);
    assert(leftmost_one(0x0) == 0x0);
    assert(leftmost_one(0x80000000) == 0x80000000);
    return 0;
}
