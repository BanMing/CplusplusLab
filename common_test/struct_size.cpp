#include <iostream>

struct data1
{
    uint64_t a : 1;
    uint64_t b : 15;

    uint64_t c : 16;
    uint64_t d : 32;
    // void* d;
    // uint64_t t :32;
    void print()
    {
        printf("a:%lld b:%lld c:%lld d:%lld \n", a, b, c, d);
        // printf("a:%lld b:%lld c:%lld d:%lld t:%lld \n", a, b, c, d, t);
        // printf("a:%lld b:%lld c:%lld d:%p t:%lld \n", a, b, c, d, t);
    }
}; // 2+15+16=33

void Run()
{
    data1 *data = new data1();
    printf("address %lld size: %d\n", (int64_t)data, sizeof(data1));
    // uint64_t test = (1 | 1 << 1 | 1 << 16 | ((int64_t)data&0xffffffff )<< 32| (uint64_t)1 << 64);
    long long int test = (1 | 1 << 1 | 1 << 16 | (int64_t)1 << 32);
    memcpy(data, &test, 96);
    printf("Test :%lld\n", test);
    data->print();
    // int64_t test = data1;
    // printf("test:%d\n", test);
}