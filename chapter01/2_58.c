#include <stdio.h>
#include <assert.h>

int is_little_endian()
{
    int x = 0xff;
    unsigned char *xp = (unsigned char *)&x;
    return xp[0] == 0xff;
}

int main(int argc, char *argv[])
{
    assert(is_little_endian());
    return 0;
}