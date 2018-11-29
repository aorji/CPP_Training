/*
Задание повышенной сложности.

Реализуйте класс SharedPtr как описано ранее. Задание немного сложнее, чем кажется на первый взгляд. Уделите особое внимание "граничным случаям" — нулевой указатель, присваивание самому себе, вызов reset на нулевом SharedPtr и прочее.

Подсказка: возможно, вам понадобится завести вспомогательную структуру.

Требования к реализации: ваш код не должен вводить или вводить что-либо, реализовывать функцию main не нужно.
*/

struct Expression;
struct Number;
struct BinaryOperation;

struct SharedPtr
{
    // реализуйте следующие методы
    //
    explicit SharedPtr(Expression *ptr = 0): ptr_(ptr), counter(0) { counter = new int(1); }
    SharedPtr(const SharedPtr &p): ptr_(p.ptr_), counter(p.counter) { ptr_ ? ++*counter: 0; }
    ~SharedPtr() {
        if (*counter && (--*counter == 0)){
            delete ptr_;
            delete counter;
        }
    }

    SharedPtr& operator=(const SharedPtr &rhs){
        if (this != &rhs) {
           	this->~SharedPtr();
            ptr_ = rhs.ptr_;
            counter = rhs.counter;
            ++*counter;
        }
        return *this;
    }
    
    Expression* get() const { return ptr_; }
    void reset(Expression *ptr = 0) {
        this->~SharedPtr();
        ptr_ = ptr;
        counter = new int(1); 
    }
    
    Expression& operator*() const { return *ptr_; }
    Expression* operator->() const { return ptr_; }
    
    
    void addCounter(int i) const { counter += i; }
    
    private:
    Expression *ptr_;
    mutable int *counter;
};