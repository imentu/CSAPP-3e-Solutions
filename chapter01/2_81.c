#include <stdio.h>
#include <assert.h>

/*
    高 w - k 位为 1，低 k 位 为 0。
*/
int A(int k)
{
    return -1 << k;
}

/*
    先将低 k + j 位置 1， 再将低 j 位置 0。
*/
int B(int k, int j)
{
    return (1 << k + j) - 1 & -1 << j;
}

int main(int argc, char *argv[])
{
    assert(A(8) == 0xFFFFFF00);
    assert(B(16, 8) == 0x00FFFF00);
    return 0;
}