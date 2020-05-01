//
// Created by BanMing on 4/29/2020.
//

class Rational {
public:
    Rational(int numerator = 0, int denominator = 1);

    int denominator() const;

    int numerator() const;

private:
    int n, d;

    friend const Rational operator*(const Rational &lhs, const Rational &rhs);
};

// 这样写可以解决 所有参数需要隐式转换时的错误
const Rational operator*(const Rational &lhs, const Rational &rhs) {
    return Rational(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
}

void Run() {}