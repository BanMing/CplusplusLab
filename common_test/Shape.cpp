//
// Created by BanMing on 2020/5/6.
//
namespace Test34 {
    class Shape {
    public:
        enum ShapeColor {
            Red, Green, Blue
        };

        // 纯虚函数，使得shape成为抽象类
//        virtual void draw() const = 0;

        // 所有形状都必须提供一个函数，用来绘出自己
        virtual void draw(ShapeColor color = Red) const;

        virtual void error(const std::string &msg);

        int objectID() const;
    };

    class Rectangle : public Shape {
        // 注意 赋予不同的缺省参数值。真糟糕
        virtual void draw(ShapeColor color = Green) const;
    };

    class Ellipse : public Shape {
        // 当以对象调用此函数，一定要指定参数值
        // 因为静态绑定下这个函数并不从其base继承缺省参数值
        // 但若以指针调用此函数，可以不指定参数值
        // 因为动态绑定下这个函数会从其base继承缺省数值
        virtual void draw(ShapeColor color) const;
    };

}

void Run() {
    Test34::Shape *ps;                          //静态类型为Shape* 无动态类型
    Test34::Shape *pe = new Test34::Ellipse;    //静态类型为Shape* 动态类型为Ellipse
    Test34::Shape *pr = new Test34::Rectangle;  //静态类型为Shape* 动态类型为Rectangle

    pe->draw(Test34::Shape::Red);        //调用Ellipse的draw Red
    pr->draw(Test34::Shape::Red);        //调用Rectangle的draw Red

    //使Shape和Rectangle都参与这方法
    pr->draw();                                //调用Rectangle的draw Red
}

