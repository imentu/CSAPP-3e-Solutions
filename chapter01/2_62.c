#include <stdio.h>
#include <assert.h>

/*
    -1 右移后若仍为 -1，则为算术右移。
*/
int int_shifts_are_arithmetic()
{
    return (-1 >> 1) == -1;
}

int main(int argc, char *argv[])
{
    assert(int_shifts_are_arithmetic());

    return 0;
}
