#include <string>
#include <iostream>

class Entity
{
private:
    std::string m_Name;
    int m_Age;

public:
    // 使用explicit可以关闭隐式构造函数
    // explicit Entity(const std::string &name) : m_Name(name), m_Age(-1) {}
    Entity(const std::string &name) : m_Name(name), m_Age(-1) {}
    Entity(int age) : m_Name("Unknown"), m_Age(age) {}
};

void PrintEntity(const Entity &entity) {}

void Run()
{
    // Entity a("BanMing");
    // Entity b(22);

    // 隐式构造函数
    Entity a = "BanMing";
    Entity b = 22;

    PrintEntity(22);
    // ""是char *
    PrintEntity(std::string("BanMing"));

    std::cin.get();
}
