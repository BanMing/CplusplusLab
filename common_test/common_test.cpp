#include <iostream>

void Run()
{
    int a = 1;
    int b = 3;

    if ((a = b) == 2)
    {
        printf("@@@@@@@@@@@@@@@@\n");
    }
    else
    {
        printf("########################\n");
    }

    printf("a = %d", a);
}