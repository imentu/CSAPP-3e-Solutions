#include <stdio.h>
#include <stdlib.h>

void good_echo()
{
    char buffer[30];
    while (fgets(buffer, 30, stdin) != NULL)
    {
        printf("%s", buffer);
    }
    printf("%s\n", buffer);
}

int main()
{
    good_echo();
    return 0;
}
