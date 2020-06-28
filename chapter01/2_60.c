#include <stdio.h>
#include <assert.h>

/*
    将b存入int变量后左移至对应字节，使用掩码将对应字节置零后置位即可。
*/
unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    int c = b, d = 0xFF;
    c <<= i * 8;
    d <<= i * 8;
    return x & ~d | c;
}

int main(int argc, char *argv[])
{
    assert(replace_byte(0x12345678, 2, 0xAB) == 0X12AB5678);
    assert(replace_byte(0x12345678, 0, 0xAB) == 0x123456AB);
    return 0;
}