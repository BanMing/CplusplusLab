#include <iostream>
#include <list>
#include <string>
#include <vector>

template <typename T>
int compare(const T &a, const T &b)
{
    return a < b ? 1 : -1;
}

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
template <typename T, size_t N>
int getArrayNum(const T (&a)[N])
{
    return N;
}

void Run()
{
    int a[6] = {2, 3, 4, 5, 6, 7};
    printf("a num:%d\n", getArrayNum(a));
}