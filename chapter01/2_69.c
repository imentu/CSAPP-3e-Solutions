#include <stdio.h>
#include <assert.h>

/*
    使用掩码保存高 n 位， 将 x 左移 n 位后或高 n 位右移 w - n 位。
*/
unsigned rotate_left(unsigned x, int n)
{
    int w = sizeof(int) << 3;
    unsigned mask = ~((unsigned)-1 >> n);
    return (x << n) | ((x & mask) >> (w - n));
}

int main(int argc, char *argv[])
{
    assert(rotate_left(0x12345678, 4) == 0x23456781);
    assert(rotate_left(0x12345678, 20) == 0x67812345);
    return 0;
}