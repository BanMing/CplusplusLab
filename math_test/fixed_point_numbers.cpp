#include <iostream>

template <size_t dp>
constexpr int32_t DoubleToFixed(double d)
{
    return int32_t(d * double(1 << dp) + (d >= 0 ? 0.5 : -0.5));
}

template <size_t dp>
constexpr double FixedToDouble(int32_t d)
{
    return double(d) / double(1 << dp);
}

void Run()
{
    // 16.16
    int32_t a = DoubleToFixed<16>(3.5);
    std::cout << a << std::endl;

    const double z = FixedToDouble<16>(a);
    std::cout << z << std::endl;

    const int32_t b = 3 * (1 << 2);
    std::cout << b << std::endl;
}