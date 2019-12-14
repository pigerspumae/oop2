#ifndef TPL_SUM_ALL_SUM_ALL_HPP
#define TPL_SUM_ALL_SUM_ALL_HPP

#include <set>
#include <map>
#include <list>
#include <forward_list>
#include <unordered_map>
#include "sum_policy.hpp"
#include "sum_traits.hpp"


template<typename T>
auto sum_all(const T &data) {
    return Policy<T>::count_sum(data);
}




#endif //TPL_SUM_ALL_SUM_ALL_HPP
