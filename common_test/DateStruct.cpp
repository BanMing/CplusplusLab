//
// Created by BanMing on 2020/4/29.
//
//explicit不允许类型隐式转换，
struct Day {
    explicit Day(int d) : val(d) {}

    int val;
};

struct Month {
    explicit Month(int m) : val(m) {}

    int val;
};

struct Year {
    explicit Year(int d) : val(d) {}

    int val;
};

class Date {
public:
    Date(const Month &m, const Day &d, const Year &y);
};

void Run() {
    //    Date d(30,3,1995); 错误，不为正确的类型
    //Date d(Day(3),Month(3),Year(1995)); 错误，不为正确的类型
    Date(Month(3), Day(30), Year(1995));
}