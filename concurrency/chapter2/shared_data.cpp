#include <string>
#include <thread>

class some_data
{
private:
    int a;
    std::string b;

public:
    void do_something() { std::cout << b << std::endl; }
};

class data_wrapper
{
private:
    some_data data;
    std::mutex m;

public:
    template <typename Function>
    void process_data(Function func)
    {
        std::lock_guard<std::mutex>(m);
        // Pass "protected" data to user-supplied function
        func(data);
    }
};

some_data *unprotected;
void malicious_function(some_data &protected_data)
{
    unexpected = &protected_data;
}

data_wrapper x;
void Run()
{
    // Pass in a malicious function
    x.process_data(malicious_function);
    // Unprotected access to protected data
    unprotected->do_something();
}
