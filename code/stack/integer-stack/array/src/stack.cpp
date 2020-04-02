#include "stack.hpp"

Stack::Stack( int const capacity )
    : data_{nullptr}
    , capacity_{capacity}
    , size_{0}
{
    data_ = new int[capacity];
}

Stack::~Stack()
{
    delete[] data_;
}

int Stack::top() const
{
    if( size_ == 0 )
    {
        throw std::out_of_range( "" );
    }

    return data_[size_ - 1];
}

bool Stack::push( int const value )
{
    data_[size_] = value;
    ++size_;

    return true;
}

int Stack::pop()
{
    if( size_ == 0 )
    {
        return 0;
    }

    int const popped = data_[size_ - 1];

    --size_;

    return popped;
}
