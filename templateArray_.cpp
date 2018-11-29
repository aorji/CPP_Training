/*
В предыдущей версии предполагается, что для типа T определены оператор присваивания и конструктор по умолчанию. При создании шаблонных классов контейнеров (вроде Array и не только) разумно стараться минимизировать требования к типам шаблонных параметров. Поэтому усложним задачу, реализуйте класс Array не полагаясь на то, что для типа T определен оператор присваивания и конструктор по умолчанию. Конструктор копирования у типа T есть.

Hints: используйте placement new и явный вызов деструктора (смотрите урок 3.4), чтобы создавать и уничтожать объекты, аллоцировать правильно выровненную память можно с помощью new char[N * sizeof(T)], где N - количество элементов массива.
*/

#include <cstddef>

template <typename T>
class Array
{
    // Список операций:
    //
    public:
    explicit Array(size_t size, const T& value = T()):size_(size){
        value_ = static_cast<T*>(operator new[] (size_ * sizeof(T)));
        for (size_t i = 0; i < size_; ++i)
            new (value_ + i) T(value);
    }
    //   конструктор класса, который создает
    //   Array размера size, заполненный значениями
    //   value типа T. Если у класса нет конструктора
    //   по умолчанию, то второй аргумент этого конструктора
    //   обязателен.
    //
    Array(){
        size_ = 0;
        value_ = 0;
    }
    //   конструктор класса, который можно вызвать
    //   без параметров. Должен создавать пустой
    //   Array.
    //
    Array(const Array & rhs):size_(rhs.size()){
        value_ = static_cast<T*>(operator new[] (size_ * sizeof(T)));
        for (size_t i = 0; i < size_; ++i)
            new (value_ + i) T(rhs.value_[i]);
    }    
    //   конструктор копирования, который создает
    //   копию параметра. Для типа T оператор
    //   присваивания не определен.
    //
    ~Array(){
        for (size_t i = 0; i < size_; ++i)
           value_[i].~T();
        operator delete[] (value_);
    }
    //   деструктор, если он вам необходим.
    //
    Array& operator=(Array const & rhs){
        if (this != &rhs){
            this->~Array();
            size_ = rhs.size();
            value_ = static_cast<T*>(operator new[] (size_ * sizeof(T)));
            for (size_t i = 0; i < size_; ++i)
                new (value_ + i) T(rhs.value_[i]);
        }
        return *this;
    }

    //   оператор присваивания.
    //
    size_t size() const {return size_;}
    //   возвращает размер массива (количество 
    //                              элементов).
    //
    T& operator[](size_t i){ return value_[i]; }
     const T& operator[](size_t i) const { return value_[i]; }
    //   две версии оператора доступа по индексу.
    
    private:
        size_t size_;
        T *value_;
};