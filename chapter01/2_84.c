#include <stdio.h>
#include <assert.h>

unsigned f2u(float x)
{
    return *(unsigned *)&x;
}

int float_le(float x, float y)
{
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    /*
        只需要处理 +0 和 -0 的情况即可，利用了 IEEE754 标准设定中浮点数位级表示下可与整数类型使用相同的排序方式。
    */
    return (ux << 1 == 0 && uy << 1 == 0) || (int)ux <= (int)uy;
}

int main(int argc, char *argv[])
{
    assert(float_le(-0, +0));
    assert(float_le(+0, -0));
    assert(float_le(0, 3));
    assert(float_le(-4, -0));
    assert(float_le(-4, 4));
    return 0;
}