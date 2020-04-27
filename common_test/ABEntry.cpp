//
// Created by BanMing on 4/27/2020.
// 确保使用所有参数之前都初始化了该参数

#include <iostream>
#include <list>

class PhoneNumber {
};

class ABEntry {
public:
    ABEntry(const std::string &name, const std::string &address, const std::list<PhoneNumber> &phones);

private:
    std::string theName;
    std::string theAddress;
    std::list<PhoneNumber> thePhones;
    int numTimesConsulted;
};

// 这些都是赋值，而非初始化参数
//ABEntry::ABEntry(const std::string &name, const std::string &address, const std::list<PhoneNumber> &phones) {
//    theName = name;
//    theAddress = address;
//    thePhones = phones;
//    numTimesConsulted = 0;
//}

// 使用 member initialization list (成员初始化列） 来做成员初始化工作
// 这里成员的初始化作为copy构造方法
ABEntry::ABEntry(const std::string &name, const std::string &address, const std::list<PhoneNumber> &phones)
        : theName(name), theAddress(address), thePhones(phones), numTimesConsulted(0) {}

void Run() {

}