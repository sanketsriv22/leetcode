#pragma once
#include <vector>
#include <iostream>

using intVector = std::vector<int>;
using floatVector = std::vector<float>;
using charVector = std::vector<char>;

// cool way to print a vector with overloading. probably should put this in a header file
template<typename T>
std::ostream& operator<<(std::ostream& stream, const std::vector<T> &vector)
{
    stream << "[";
    for (auto iter = vector.begin(); iter != vector.end(); iter++)
    {
        if (iter != vector.begin()) stream << ", ";
        stream << *iter;
    }
    stream << "]";
    return stream;
}