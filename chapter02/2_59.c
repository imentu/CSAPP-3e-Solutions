#include <stdio.h>
#include <assert.h>

/*
    x & 0xFF 仅保留最低字节的1，y & ~0xFF 将最低字节置0，然后 x | y 将二者组合起来。
*/
int main(int argc, char *argv[])
{
    int x = 0x89ABCDEF;
    int y = 0x76543210;

    assert(((x & 0xFF) | (y & ~0xFF)) == 0x765432EF);
    return 0;
}