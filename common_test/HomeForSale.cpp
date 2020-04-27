//
// Created by BanMing on 4/27/2020.
//

class HomeForSale {
public:
    HomeForSale() {

    }

private:
    // 只有声明，参数名并非必要，只不过大家习惯写出来。
    HomeForSale(const HomeForSale &);

    HomeForSale &operator=(const HomeForSale);
};

void Run() {
    HomeForSale homeForSale1;
    HomeForSale homeForSale2;
    // 编译器不会放过他
    // homeForSale1 = homeForSale2;

}