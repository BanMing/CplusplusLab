#include <iostream>
struct Test
{
    int a;
};

void Add(Test *res, const Test *left, const Test *right)
{
    res->a = left->a + right->a;
}

void Run()
{
    Test* test1 = new Test();
    test1->a = 1;

    Test* test2 = new Test();
    test2->a = 2;

    // Test* test3 = new Test();
    // test3->a = 3;

    Add(test1, test2, test1);
    printf("res:%d\n", test1->a);
}