//
// Created by BanMing on 2020/4/27.
//

#ifndef CPLUSPLUSLAB_GAMEPLAYERTEST_H
#define CPLUSPLUSLAB_GAMEPLAYERTEST_H


class GamePlayerTest {
public:
    // 使用static可以在头文件中声名并且不赋值
    static const double FudgeFactor;
    // 不使用static就需要在此赋值
    const int TestConstInt = 10;
};


#endif //CPLUSPLUSLAB_GAMEPLAYERTEST_H
