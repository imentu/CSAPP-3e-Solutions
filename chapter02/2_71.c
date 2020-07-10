#include <stdio.h>
#include <assert.h>

typedef unsigned packet_t;

/*
    A. 未将指定字节符号扩展为 32 位int。
    B. 将对应字节左移至最高字节后利用 int 类型算术右移移动到最低位。
*/
int xbyte(packet_t word, int bytenum)
{
   return (int)word << ((3 - bytenum) << 3) >> 24;
}

int main(int argc, char *argv[])
{
    assert(xbyte(0xAABBCCDD, 1) == 0xFFFFFFCC);
    assert(xbyte(0x00112233, 2) == 0x11);
    return 0;
}