#include <stdio.h>
#include <assert.h>

/*
    只要任意奇数位为 1，返回 1。
*/
int any_odd_one(unsigned x)
{
    return !!(x & 0xAAAAAAAA);
}

int main(int argc, char const *argv[])
{
    assert(any_odd_one(0x2));
    assert(!any_odd_one(0x4));
    return 0;
}
