/*
(Задание повышенной сложности) Предполагаемое решение этого задания не переносимо с точки зрения стандарта, однако оно проверено на различных версиях компиляторов g++/clang++/msvc. Решение этого задания не обязательно для получения диплома по этому курсу, однако мы считаем его полезным, чтобы лучше понять как устроены виртуальные функции внутри.

Вам требуется реализовать функцию, которая принимает на вход два указателя на базовый класс Expression, и возвращает true, если оба указателя указывают на самом деле на объекты одного и того же класса, и false в противном случае (т.е. если оба указателя указывают на BinaryOperation, то возвращается true, а если один из них указывает на Number, а второй на BinaryOperation, то false).

Требования к реализации: пользоваться typeid и dynamic_cast запрещено. Вызывать методы по переданным указателям запрещено.
*/

bool check_equals(Expression const *left, Expression const *right)
{
    return *((int**)left) == *((int**)right);
}

//через полиморфизм

bool check_equals(Number const *left, Number const *right)
{
    return true;
}

bool check_equals(Number const *left, BinaryOperation const *right)
{
    return false;
}

bool check_equals(BinaryOperation const *left, Number const *right)
{
    return false;
}

bool check_equals(BinaryOperation const *left, BinaryOperation const *right)
{
    return true;
}