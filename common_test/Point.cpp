//
// Created by BanMing on 4/27/2020.
//
#include <memory>

class Point {
public:
    Point(int x, int y);

    ~Point();

    void setX(int newVal);

    void setY(int newVal);

private:
    int x, y;
};


struct RectData {
    Point ulhc;
    Point lrhc;
};

class Rectangle {
private:
    std::shared_ptr<RectData> pData;
public:
    Point &upperLeft() const { return pData->ulhc; }

    const Point &lowerRight() const { return pData->lrhc; }

    Rectangle(Point ulhc, Point lrhc);
};

void Run() {
    Point coord1(0, 0);
    Point coord2(100, 100);
    const Rectangle rec(coord1, coord2);
    // 这里理论上是不能修改的，但是这里返回了以引用Point对象
    rec.upperLeft().setX(2);

    // 如此就是正确的lowerRight在函数前加了一个const 使得返回一个常引用
//    rec.lowerRight().setX(2);
}