//
// Created by BanMing on 2020/5/1.
//
#include <vector>

class WidgetImpl {
private:
    int a, b, c;
    std::vector<double> v;
};

class Widget {
public:
    Widget(const Widget &rhs);

    Widget &operator=(const Widget &rhs) {
        *pImpl = *(rhs.pImpl);
    }

    void swap(Widget &other) {
        using std::swap;
        swap(pImpl, other.pImpl);
    }

private:
    WidgetImpl *pImpl;
};

namespace std {
//    template<typename T>
//    void swap(T &a, T &b) {
//        T temp(a);
//        a = b;
//        b = temp;
//    }

//    template<> //修订版的std::swap特化版
//    void swap<Widget>(Widget &a Widget &b) {
//        a.swap(b);
//    }
}

void Run() {}

