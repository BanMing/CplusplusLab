#include <iostream>
#include <list>
#include <string>
#include <vector>

// 16.2
template <typename T>
int compare(const T &a, const T &b)
{
    return a < b ? 1 : -1;
}

// 16.4
template <typename TContainer, typename TValue>
bool find(const TContainer &container, const TValue &findValue)
{
    for (const TValue &value : container)
    {
        if (value == findValue)
        {
            return true;
        }
    }

    return false;
}

void Test1()
{
    std::vector<int> a = {1, 3, 4, 5};
    std::list<std::string> b = {"2", "3", "7"};
    printf("find 4 in a %d\n", find(a, 4));
    printf("find 2 in a %d\n", find(a, 2));

    printf("find \"4\" in b %d \n", find(b, std::string("4")));
    printf("find \"3\" in b %d \n", find(b, std::string("3")));
}
// 16.5
template <typename T, size_t N>
void prints(const T (&container)[N])
{
    for (size_t i = 0; i < N; i++)
    {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;
}

void Test2()
{
    int a[6] = {2, 3, 4, 5, 6, 7};
    std::string b[6] = {"2", "3", "4", "5", "6", "7"};
    prints(a);
    prints(b);
}

// 16.6
template <typename T, size_t N>
T *begin(const T (&a)[N])
{
    return &a[0];
}

template <typename T, size_t N>
T *end(const T (&a)[N])
{
    return &a[0] + N;
}

// 16.7
template <typename T, size_t N>
constexpr int getArrayNum(const T (&a)[N])
{
    return N;
}

void Test4()
{
    int a[6] = {2, 3, 4, 5, 6, 7};
    printf("a num:%d\n", getArrayNum(a));
}

void Run()
{

}