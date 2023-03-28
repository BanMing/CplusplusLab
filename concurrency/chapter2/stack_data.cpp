#include <stack>
#include <vector>
#include <iosteam>

std::stack<int> some_stack;

void do_someting(int value)
{
    std::cout << value << std::endl;
}

void test1()
{
    if (!some_stack.empty())
    {
        int const value = some_stack.top();
        some_stack.pop();
        do_someting(value);
    }
}

// Pass in a reference
void cache_reference()
{
    if (!some_stack.empty())
    {
        std::vector<int> result;
        some_stack.pop(result);
    }
}