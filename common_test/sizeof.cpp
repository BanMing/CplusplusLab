#include <iostream>
struct test_data2
{
    int d;
    int e;
}; // 8

struct test_data1
{
    int a;
    int b;
    short c;
    static int m;
    test_data2 *addr()
    {
        return (test_data2 *)((char *)this + sizeof(test_data1));
    };
}; // 10



struct test_data3
{
    test_data1 data1;

    test_data2 data2s[5];
};

void Run()
{
    printf("data 1 size: %d \n", sizeof(test_data1));
    printf("struct data 1 size: %d \n", sizeof(struct test_data1));

    printf("data 2 size: %d \n", sizeof(test_data2));
    printf("struct data 2 size: %d \n", sizeof(struct test_data2));

    test_data3 data;

    printf("data2 address %p \n",&data.data2s);
    printf("data1 2 address %p \n",data.data1.addr());
}