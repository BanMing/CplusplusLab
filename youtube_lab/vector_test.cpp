#include <vector>
#include <iostream>

class Vertex
{
private:
    int x, y, z;

public:
    Vertex(int a, int b, int c) : x(a), y(b), z(c) {}
    Vertex(const Vertex &other)
    {
        std::cout << "Copy!!!" << std::endl;
    }
};

void Run()
{
    std::vector<Vertex> vertices;
    // vertices.push_back(Vertex(1, 2, 3));
    // vertices.push_back(Vertex(4, 5, 6));
    // vertices.push_back(Vertex(7, 8, 9));
    vertices.reserve(3);
    vertices.emplace_back(1, 2, 3);
    vertices.emplace_back(4, 2, 3);
    vertices.emplace_back(5, 2, 3);

    // std::cin.get();
}