//
// Created by BanMing on 4/29/2020.
//

class Rational {
public:
    Rational(int numerator = 0, int denominator = 1);

private:
    int n, d;

    friend const Rational operator*(const Rational &lhs, const Rational &rhs);
};

void Run() {}