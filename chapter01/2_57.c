#include "show_bytes.h"

void show_short(short x)
{
    show_bytes(&x, sizeof(short));
}

void show_double(double x)
{
    show_bytes(&x, sizeof(double));
}

void show_long(long x)
{
    show_bytes(&x, sizeof(long));
}

int main()
{
    short a = 1234;
    double b = 0.1234;
    long c = 1234;
    show_short(a);
    show_double(b);
    show_long(c);

    return 0;
}