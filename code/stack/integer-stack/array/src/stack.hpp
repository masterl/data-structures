#ifndef INTEGER_ARRAY_STACK_H
#define INTEGER_ARRAY_STACK_H

#include <stdexcept>

class Stack
{
    static int const default_capacity = 32;

    public:
    Stack( int const capacity = default_capacity );

    ~Stack();

    ssize_t size() const
    {
        return size_;
    }

    ssize_t capacity() const
    {
        return capacity_;
    }

    int top() const;
    bool push( int const value );
    int pop();

    private:
    int *data_;
    ssize_t const capacity_;
    ssize_t size_;
};

#endif
