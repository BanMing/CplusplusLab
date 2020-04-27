//
// Created by BanMing on 2020/4/27.
//

#include "GamePlayerTest.h"
#include <iostream>
#include <string>

const double GamePlayerTest::FudgeFactor = 15;
//如果在没有使用static const 无法再此赋值
//const int GamePlayerTest::TestConstInt =10;

void Run() {
    GamePlayerTest gamePlayerTest;
    std::cout << std::to_string(gamePlayerTest.FudgeFactor) << std::endl;
    std::cout << std::to_string(gamePlayerTest.TestConstInt) << std::endl;
}