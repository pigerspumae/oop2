#ifndef QUSORT_QUSORT_HPP
#define QUSORT_QUSORT_HPP

#include <iostream>
#include <functional>
#include <algorithm>
#include <iterator>


template<typename RandomAccessIterator, typename Compare>
void quick_sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp) {
    if (first != last) {
        RandomAccessIterator left = first;
        RandomAccessIterator right = last;
        RandomAccessIterator pivot = left++;
        while (left != right) {
            if (comp(*left, *pivot)) {
                ++left;
            } else {
                while ((left != --right) && comp(*pivot, *right));
                auto tmp_var = *left;
                *left = *right;
                *right = tmp_var;
            }
        }
        left--;
        auto tmp_var = *left;
        *left = *first;
        *first = tmp_var;
        quick_sort(first, left, comp);
        quick_sort(right, last, comp);
    }
}

template<typename RandomAccessIterator>
inline void quick_sort(RandomAccessIterator first, RandomAccessIterator last) {
    quick_sort(first, last, std::less_equal<typename std::iterator_traits<RandomAccessIterator>::value_type>());
}

#endif
