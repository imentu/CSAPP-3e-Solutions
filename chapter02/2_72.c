#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

/*
    A.sizeof 返回值是 unsigned 类型，int 会默认转换为 unsigned 结果永远大于 0，将 unsigned 转换为 int 即可正确比较。
*/
void copy_int(int val, void *buf, int maxbytes)
{

    if (maxbytes >= (int)sizeof(val))
    {
        memcpy(buf, (void *)&val, sizeof(val));
    }
}

int main(int argc, char *argv[])
{
    int maxbytes = sizeof(int) * 10;
    void *buf = malloc(maxbytes);
    int val;

    val = 0x12345678;
    copy_int(val, buf, maxbytes);
    assert(*(int *)buf == val);

    val = 0xAABBCCDD;
    copy_int(val, buf, 0);
    assert(*(int *)buf != val);

    free(buf);
    return 0;
}