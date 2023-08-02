#include <iostream>
void RefrenceTest(int32_t a[])
{
    a[2] = 3;
}

void Run()
{
    int a[6];
    for (size_t i = 0; i < 3; i++)
    {
        a[i] = 2;
        printf("i:%d num:%d\n", i, a[i]);
    }
    printf("@#\n");
    RefrenceTest(a);
    for (size_t i = 0; i < 3; i++)
    {
        printf("i:%d num:%d\n", i, a[i]);
    }
}