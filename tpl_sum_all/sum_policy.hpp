#ifndef TPL_SUM_ALL_SUM_POLICY_HPP
#define TPL_SUM_ALL_SUM_POLICY_HPP

#include <type_traits>
#include "sum_traits.hpp"

template<typename T, typename Enable = void>
class Policy {};

//simple type
template<typename T>
class Policy<T, typename std::enable_if<(std::is_arithmetic<T>::value)
                      || std::is_same<T, std::string>::value>::type> {
public:
    typedef SumTraits<T> Traits;

    static auto count_sum(T data) {
        return Traits::same(data);
    }
};

//container<type>
template<typename T>
class Policy<T, typename std::enable_if<
        (std::is_arithmetic<typename T::value_type>::value &&
        !std::is_same<T, std::string>::value) ||
         std::is_same<typename T::value_type, std::string>::value>::type> {
public:
    typedef SumTraits<typename T::value_type> Traits;

    static auto count_sum(const T &data) {
        typename Traits::SumT result{};
        for (auto i : data) {result += i;}
        return result;
    }
};

//container<type1, type2>
template<typename T>
class Policy< T, typename std::enable_if<std::is_arithmetic<typename T::mapped_type>::value
                       || std::is_same<typename T::mapped_type, std::string>::value>::type>{
public:
	typedef SumTraits<typename T::mapped_type> Traits;

    static auto count_sum(const T &data) {
        typename Traits::SumT result{};
        for (auto i : data) { result += i.second; }
        return result;
	}
};

#endif //TPL_SUM_ALL_SUM_POLICY_HPP

