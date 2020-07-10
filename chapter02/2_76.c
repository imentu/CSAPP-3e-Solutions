#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/* 
    可利用除法验证是否溢出。
    注意对除0的处理。
*/
void *another_calloc(size_t nmemb, size_t size)
{
    if (nmemb == 0 || size == 0)
    {
        return NULL;
    }
    size_t mul = nmemb * size;
    if (mul / size == nmemb)
    {
        void *s = malloc(nmemb * size);
        if (s != NULL)
        {
            memset(s, 0, size);
        }
        return s;
    }
    else
    {
        return NULL;
    }
}

int main(int argc, char *argv[])
{
    void *p;
    p = another_calloc(0x1234, 1);
    assert(p != NULL);
    free(p);

    p = another_calloc(SIZE_MAX, 2);
    assert(p == NULL);
    free(p);
    return 0;
}