#include <include/gtest/gtest.h>
#include "../qusort.hpp"

bool comp_int(int a, int b) {
    return (a > b);
}

bool comp_float(float a, float b) {
    return (a > b);
}

bool comp_char(char a, char b) {
    return (a > b);
}

TEST(sort_vector_int, empty) {
    std::vector<int> control{};
    std::vector<int> check{};

    std::sort(control.begin(), control.end());
    quick_sort(check.begin(), check.end());
    if (control == check) SUCCEED();
    else
        ADD_FAILURE();
}

TEST(sort_vector_int, like_empty_bb) {
    std::vector<int> control{};
    std::vector<int> check{};

    std::sort(control.begin(), control.begin());
    quick_sort(check.begin(), check.begin());
    if (control == check) SUCCEED();
    else
        ADD_FAILURE();
}

TEST(sort_vector_int, like_empty_ee) {
    std::vector<int> control{};
    std::vector<int> check{};

    std::sort(control.end(), control.end());
    quick_sort(check.end(), check.end());
    if (control == check) SUCCEED();
    else
        ADD_FAILURE();
}

TEST(sort_vector_int, filled) {
    std::vector<int> control{13, 14, 10, 11, 12, 15, 9, 16, 8, 17};
    std::vector<int> check{13, 14, 10, 11, 12, 15, 9, 16, 8, 17};

    std::sort(control.begin(), control.end());
    quick_sort(check.begin(), check.end());
    if (control == check) SUCCEED();
    else
        ADD_FAILURE();
}

TEST(sort_vector_int, filled_with_comp) {
    std::vector<int> control{13, 14, 10, 11, 12, 15, 9, 16, 8, -17};
    std::vector<int> check{13, 14, 10, 11, 12, 15, 9, 16, 8, -17};

    std::sort(control.begin(), control.end(), comp_int);
    quick_sort(check.begin(), check.end(), comp_int);
    if (control == check) SUCCEED();
    else
        ADD_FAILURE();
}

TEST(sort_vector_int_random, filled_with_comp) {
    std::vector<int> control{};
    std::vector<int> check{};
    int size = 1000;
    int i = 0;
    int n = 0;
    std::srand(1);
    for (i = 0; i < size; i++) {
        n = -20 + rand() % (20 - (-20));
        control.push_back(n);
        check.push_back(n);
    }
    std::sort(control.begin(), control.end(), comp_int);
    quick_sort(check.begin(), check.end(), comp_int);
    if (control == check) SUCCEED();
    else
        ADD_FAILURE();
}


TEST(sort_vector_uint_random, filled_with_comp) {
    std::vector<unsigned int> control{};
    std::vector<unsigned int> check{};
    int size = 1000;
    int i = 0;
    unsigned int n = 0;
    std::srand(1);
    for (i = 0; i < size; i++) {
        n = 0 + rand() % (100 - 0);
        control.push_back(n);
        check.push_back(n);
    }
    std::sort(control.begin(), control.end(), comp_int);
    quick_sort(check.begin(), check.end(), comp_int);
    if (control == check) SUCCEED();
    else
        ADD_FAILURE();
}

TEST(sort_vector_char_random, filled_with_comp) {
    std::vector<char> control{};
    std::vector<char> check{};
    int size = 1000;
    int i = 0;
    char n = 0;
    std::srand(1);
    for (i = 0; i < size; i++) {
        n = 0 + rand() % (100 - 0);
        control.push_back(n);
        check.push_back(n);
    }
    std::sort(control.begin(), control.end(), comp_char);
    quick_sort(check.begin(), check.end(), comp_char);
    if (control == check) SUCCEED();
    else
        ADD_FAILURE();
}


TEST(sort_vector_float_random, filled_with_comp) {
    std::vector<float> control{};
    std::vector<float> check{};
    int size = 1000;
    int i = 0;
    float n = 0;
    std::srand(1);
    for (i = 0; i < size; i++) {
        n = (0 + rand() % (100 - 0)) / 10.0;
        control.push_back(n);
        check.push_back(n);
    }
    std::sort(control.begin(), control.end(), comp_float);
    quick_sort(check.begin(), check.end(), comp_float);
    if (control == check) SUCCEED();
    else
        ADD_FAILURE();
}


TEST(sort_array, filled) {
    std::array<int, 100> arr1, arr2;
    int size = 100;
    int i = 0;
    int n = 0;
    std::srand(1);
    for (i = 0; i < size; i++) {
        n = (0 + rand() % (100 - 0));
        arr1[i] = n;
        arr2[i] = n;
    }
    std::sort(arr1.begin(), arr1.end());
    quick_sort(arr2.begin(), arr2.end());
    if (arr1 == arr2) SUCCEED();
    else
        ADD_FAILURE();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
