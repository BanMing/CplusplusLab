//
// Created by WP on 4/22/2020.
//https://docs.microsoft.com/en-us/cpp/cpp/extern-cpp?view=vs-2019

#include <iostream>
#include <string>

int i = 42;
extern const int j = 333;

void printA() {
    std::cout << "file A" << std::endl;
    std::cout << std::to_string(i) << std::endl;
    std::cout << std::to_string(j) << std::endl;
}
