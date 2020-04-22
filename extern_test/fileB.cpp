//
// Created by WP on 4/22/2020.
//
#include <iostream>
#include <string>

//仅仅为声明
extern int i;
extern const int j;

void printB() {
    std::cout << "file B" << std::endl;
    std::cout << std::to_string(i) << std::endl;
    std::cout << std::to_string(j) << std::endl;
}