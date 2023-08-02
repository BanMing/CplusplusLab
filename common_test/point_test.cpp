#include <iostream>
const int test =3;
struct point_test
{
    int a;
    ~point_test() { printf("~point_test\n"); }
};

void Test(point_test *&test, int value)
{
    // test->a = value;
    {
        point_test temp;
        temp.a = value;
        // Test(&temp, 2);
        test = &temp;
    }
}

void Run()
{
    point_test *test;
    Test(test, 2);
    // 内存没有被占用，所以值还是2,但是对象时被销毁了的。
    // for (size_t i = 0; i < 100000; i++)
    // {
    //      point_test temp;
    // }

    // {
    //     point_test temp;
    //     temp.a = 1;
    //     Test(&temp, 2);
    //     test = &temp;
    // }
    // {
    //     point_test temp;
    //     temp.a = 2;
    //     // Test(&temp);
    //     // test = &temp;
    // }

    // printf("test:%d\n", test->a);
    printf("test adress:%lld\n",(int64_t)&test);

}