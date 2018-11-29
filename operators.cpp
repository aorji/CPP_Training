/*
Вам дан класс Rational, который описывает рациональное число. В нем определены методы add, sub, mul и div, которые прибавляют к нему число, отнимают число, умножают на число и делят на число соответственно. Кроме того в нем определен метод neg, который меняет знак на противоположный.

Вам нужно определить операторы +=, -=, *=, /= для класса Rational так, чтобы они могли принимать в качестве аргументов и объекты типа Rational и целые числа. Кроме того вам необходимо определить операторы унарного минуса и плюса для класса Rational.

Требования к реализации: ваш код не должен вводить или вводить что-либо, реализовывать функцию main не нужно. Кроме того, нельзя (это совершенно не нужно) использовать динамическую память или подключать какие-либо библиотеки.

*/

struct Rational
{
    Rational(int numerator = 0, int denominator = 1);

    void add(Rational rational);
    void sub(Rational rational);
    void mul(Rational rational);
    void div(Rational rational);

    void neg();
    void inv();
    double to_double() const;

    Rational operator+() const { return *this; }
    Rational operator-() const { return Rational(-numerator_, denominator_); }
    
    Rational & operator+=(Rational b) { add(b); return *this; }
    Rational & operator-=(Rational b) { sub(b); return *this; }
    Rational & operator*=(Rational b) { mul(b); return *this; }
    Rational & operator/=(Rational b) { div(b); return *this; }
    /*
    Добавьте в класс Rational оператор приведения к double. Все операторы из предыдущих заданий отсутствуют и реализовывать их не нужно. Метод to_double можно использовать в этом задании.

    Важное замечание: добавлять оператор преобразования к double в класс Rational не самая удачная идея, например, потому, что при таком преобразовании может происходить потеря точности. Эта задача дана исключительно с целью ознакомления с правильным порядком перегрузки таких операторов.

    Требования к реализации: ваш код не должен вводить или вводить что-либо, реализовывать функцию main не нужно.
    */
    operator double() const { return to_double(); }
                                               
private:
    int numerator_;
    int denominator_;
};
/*
Определите для класса Rational операторы сложения, вычитания, умножения и деления, так чтобы объекты типа Rational можно было складывать (вычитать, умножать и делить) не только друг с другом но и с целыми числами.

Требования к реализации: ваш код не должен вводить или выводить что-либо, реализовывать функцию main не нужно.
*/
#define GENERATE_OP(op) \
    Rational operator op(Rational lhs, Rational rhs) { \
    return lhs op##= rhs; \
}

GENERATE_OP(+)
GENERATE_OP(-)
GENERATE_OP(*)
GENERATE_OP(/)

/*
Еще одна важная группа операторов, которые полезно реализовать для класса рациональных чисел — это операторы сравнения. Реализуйте операторы <, <=, >, >=, ==, != для класса Rational так, чтобы можно было сравнивать объекты класса Rational не только друг с другом, но и с целыми числами.

При решении задания не используйте метод to_double, он введен в класс, в первую очередь, для удобства тестирования. Вы можете определять любые вспомогательные методы или функции если необходимо.

Требования к реализации: ваш код не должен вводить или вводить что-либо, реализовывать функцию main не нужно.
*/

bool operator==(Rational lhs, Rational rhs){
    lhs.sub(rhs);
    return lhs.getN() == 0;
};
bool operator!=(Rational lhs, Rational rhs) { return !(lhs == rhs); }
bool operator<(Rational lhs, Rational rhs) {
    lhs.sub(rhs);
    return lhs.getN() < 0;
}
bool operator>(Rational lhs, Rational rhs) { return rhs < lhs; }
bool operator<=(Rational lhs, Rational rhs) { return !(rhs < lhs); }
bool operator>=(Rational lhs, Rational rhs) { return !(lhs < rhs); }
