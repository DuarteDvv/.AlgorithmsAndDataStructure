#ifndef COUNTING_PAIR
#define COUNTING_PAIR

#include "tools.hpp"

template <typename T>
class CountingPair {
public:
    T first;
    int second;

    CountingPair() : first(T()), second(0) {}

    CountingPair(const T& t1, int count) : first(t1), second(count) {}
};

#endif
