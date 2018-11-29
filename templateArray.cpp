/*

Реализуйте шаблонную версию класса Array. Список всех операций, которые должен поддерживать класс Array, приведен в шаблоне кода.

*/

#include <cstddef>
template <typename T>
class Array
{
    // Список операций:
    //
    public:
    explicit Array(size_t size = 0, const T& value = T()):size_(size), value_(new T[size]){
        for(size_t i = 0; i < size; ++i){
            value_[i] = value;
        }
    } 

    Array(const Array & rhs):size_(rhs.size()), value_(new T[rhs.size()]){
       	for(size_t i = 0; i < size_; ++i){
            value_[i] = rhs.value_[i];
        }
    }   

    ~Array(){ delete [] value_; }

    Array& operator=(Array const & rhs){
        if (this != &rhs){
            delete [] value_;
            size_ = rhs.size();
            value_ = new T[rhs.size()];
            for(size_t i = 0; i < size_; ++i){
            	value_[i] = rhs.value_[i];
        	}
        }
        return *this;
    }

    size_t size() const {return size_;}
    T * value() const { return value_; }

    T& operator[](size_t i){ return value_[i]; }
    
    const T& operator[](size_t i) const { return value_[i]; }
  
    private:
        size_t size_;
        T *value_;
};