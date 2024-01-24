#include <stdio.h>

//main that prints out input
int main(int argc, char **argv)
{
    int i;

    i = 0;
    while (i++ < argc - 1)
        printf("%s\n", argv[i]);
    return (0);
}