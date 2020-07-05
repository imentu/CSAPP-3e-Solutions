#include <stdio.h>

int main(int argc, char const *argv[])
{
    unsigned x = 0x40490FDB;
    printf("%f\n", *(float *)&x);
    return 0;
}
