//
// Created by BanMing on 4/27/2020.
//

template<class T>
class NameObject {
public:
    //以下构造函数如今不再接受一个const名称，因为
    //如今是个reference-to-non-const string，先前那个char * 构造函数
    //已经过去了，因为必须有个string可供涉及
    NameObject(std::string &name, const T &value);

private:
//    std::string &nameValue; // 这如今是个reference
    const T objectValue;    // 这如今是个const
};

void Run() {
    std::string newDog("Persephone");
    std::string oldDog("Satch");
    NameObject<int> p(newDog, 2);
    NameObject<int> s(oldDog, 36);
    // 不能编译过，因为nameValue为引用类型，不能对引用自身修改
    // 对于const 类型参数
    //   p = s;
}