#include <iostream>

class Entity
{
public:
    int x;
    Entity()
    {
        std::cout << "Created Entity" << std::endl;
    }
    ~Entity()
    {
        std::cout << "Destroyed Entity" << std::endl;
    }
};

class ScopePtr
{
public:
    Entity *entityPtr;
    ScopePtr(Entity *e) : entityPtr(e) {}
    ~ScopePtr() { delete entityPtr; }
};

void Run()
{

    {
        // Entity e;
        // Entity *e = new Entity();
        ScopePtr e = new Entity();
    }
    std::cin.get();
}