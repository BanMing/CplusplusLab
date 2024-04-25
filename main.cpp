#include <iostream>
const int ad = 3;
// #include "common_test/VirtualTemplate.cpp"
#include "template/compare_test.h"

int main()
{
    std::cout << "Hello" << std::endl;
    printf("ad adress:%lld\n",(int64_t)&ad);
    Run();
    return 0;
}
