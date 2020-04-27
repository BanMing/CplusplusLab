//
// Created by BanMing on 4/27/2020.
//

#ifndef CPLUSPLUSLAB_TEXTBLOCK_H
#define CPLUSPLUSLAB_TEXTBLOCK_H

class TextBlock {
public:
    TextBlock(const std::string str) {
        this->text = str;
    }

    // operator [] const 对象
    const char &operator[](std::size_t position) const { return text[position]; }

    //operator[] for non-const 对象
    char &operator[](std::size_t position) { return text[position]; }

private:
    std::string text;
};


void Run() {
    TextBlock tb("Hello");
    // 调用non - const
    std::cout << tb[0] << std::endl;

    //调用 const
    const TextBlock ctb("World");
    std::cout << ctb[0] << std::endl;

    // 没问题 写一个non-const TextBlock
    tb[0] = 'x';
    // 没问题 读一个non-const TextBlock
    std::cout << tb[0] << std::endl;

    // 有问题 此处无法修改一个常对象ctb
    // ctb[0]='x';
    // 没问题 读一个 const TextBlock
    std::cout << ctb[0] << std::endl;

}

#endif //CPLUSPLUSLAB_TEXTBLOCK_H
