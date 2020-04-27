//
// Created by BanMing on 4/27/2020.
//

#ifndef CPLUSPLUSLAB_CTEXTBLOCK_H
#define CPLUSPLUSLAB_CTEXTBLOCK_H

#include <cstring>

class CTextBook {
public:
    CTextBook(char *str) {
        pText = str;
    }

    // bitwise const 声明 不恰当
    char &operator[](size_t position) const { return pText[position]; }

    std::size_t length() const;

private:
    char *pText;

    // 设置这些参数可以再const函数中被修改
    mutable std::size_t textLength; // 最近一次计算的文本区块长度
    mutable bool lengthIsValid; //目前的长度是否有效
};

std::size_t CTextBook::length() const {
    if (!lengthIsValid) {
        // 在const函数内 不能复制给textLength、lengthIsValid
        textLength = std::strlen(pText);
        lengthIsValid = true;
    }
    return textLength;
}

void Run() {
    // 声明一个常量对象
    const CTextBook cctb(const_cast<char *>("Hello"));
    std::cout << cctb[0] << std::endl;
    // 调用const operation [] 取得一个指针 指向cctb的数据
    char *pc = &cctb[0];
    //cctb 现在有了“Jello"这样的内容
    // 这里会卡主
    //    *pc = 'J';
    //    pc[0] = 'J';
    std::cout << cctb[0] << std::endl;
    std::cout << pc << std::endl;
}

#endif //CPLUSPLUSLAB_CTEXTBLOCK_H
