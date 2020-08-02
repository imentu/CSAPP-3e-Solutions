#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void *basic_memset(void *s, int c, size_t n)
{
    size_t cnt = 0;
    unsigned char *schar = s;
    while (cnt < n)
    {
        *schar++ = (unsigned char)c;
        cnt++;
    }
    return s;
}

void *effective_memset(void *s, unsigned long cs, size_t n)
{
    size_t K = sizeof(unsigned long);
    size_t cnt = 0;
    unsigned char *sc = s;
    while (cnt < n && (unsigned long)s % K != 0)
    {
        *sc++ = (unsigned char)cs;
        cnt++;
    }
    n -= cnt;
    size_t ccnt = n % K;
    size_t lcnt = n / K;
    unsigned long *lc = (unsigned long *)sc;
    while (lcnt)
    {
        *lc++ = cs;
        lcnt -= 1;
    }
    sc = (unsigned char *)lc;
    while (ccnt)
    {
        *sc++ = (unsigned char)cs;
        ccnt -= 1;
    }
}

int main(int argc, char *argv[])
{
    size_t space = sizeof(char) * 65537;

    void *basic_space = malloc(space);
    void *effective_space = malloc(space);

    int basic_fill = 0xFF;
    unsigned long effective_fill = ~0;

    basic_memset(basic_space, basic_fill, space);
    effective_memset(effective_space, effective_fill, space);

    assert(memcmp(basic_space, effective_space, space) == 0);

    free(basic_space);
    free(effective_space);
    return 0;
}