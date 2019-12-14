#ifndef TPL_SUM_ALL_SUM_TRAITS_HPP
#define TPL_SUM_ALL_SUM_TRAITS_HPP

#include <string>

template<typename T>
class SumTraits {
public:
    typedef T SumT;

    static SumT same(T data) { return (SumT) data; }
};

template<>
class SumTraits<char> {
public:
    typedef std::string SumT;

    static SumT same(char data) {
        std::string s = "";
        s += data;
        return s;
    }
};


template<>
class SumTraits<unsigned char> {
public:
    typedef unsigned long SumT;

    static SumT same(unsigned long data) { return (SumT) data; }
};


template<>
class SumTraits<short> {
public:
    typedef long SumT;

    static SumT same(short data) { return (SumT) data; }
};

template<>
class SumTraits<unsigned short> {
public:
    typedef unsigned long SumT;

    static SumT same(unsigned short data) { return (SumT) data; }
};


template<>
class SumTraits<int> {
public:
    typedef long SumT;

    static SumT same(int data) { return (SumT) data; }
};

template<>
class SumTraits<unsigned int> {
public:
    typedef unsigned long SumT;

    static SumT same(unsigned int data) { return (SumT) data; }
};


template<>
class SumTraits<float> {
public:
    typedef double SumT;

    static SumT same(float data) { return (SumT) data; }
};


#endif //TPL_SUM_ALL_SUM_TRAITS_HPP
