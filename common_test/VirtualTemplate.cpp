#include <iostream>

class Base
{
public:
    // virtual ~Base() {}

    template <typename T>
    void VirtualTemplateFunction(T value)
    {
        std::cout << "Base::VirtualTemplateFunction called with value: " << value << std::endl;
    }
};

class Derived : public Base
{
public:
    template <typename T>
    void VirtualTemplateFunction(T value) 
    {
        std::cout << "Derived::VirtualTemplateFunction called with value: " << value << std::endl;
    }
};

void Run()
{
    Base *base = new Derived();

    base->VirtualTemplateFunction(42);

    delete base;
}