#include <include/gtest/gtest.h>
#include <unordered_set>
#include "../sum_all.hpp"


TEST(simple_type, integer_int) {
    int integer = 5;
    auto res_int = sum_all(integer);
    EXPECT_EQ(integer, res_int);
}

TEST(simple_type, integer_uint) {
    unsigned int integer = 5;
    auto res_int = sum_all(integer);
    EXPECT_EQ(integer, res_int);
}

TEST(simple_type, symbol_char) {
    char integer = 'd';
    auto res_int = sum_all(integer);
    EXPECT_EQ("d", res_int);
}

TEST(simple_type, integer_uchar) {
    unsigned char integer = 5;
    auto res_int = sum_all(integer);
    EXPECT_EQ(integer, res_int);
}

TEST(simple_type, integer_short) {
    short integer = 5;
    auto res_int = sum_all(integer);
    EXPECT_EQ(integer, res_int);
}

TEST(simple_type, integer_ushort) {
    unsigned short integer = 5;
    auto res_int = sum_all(integer);
    EXPECT_EQ(integer, res_int);
}


TEST(simple_type, fractional_f) {
    float fraction = 5.5;
    auto res_float = sum_all(fraction);
    EXPECT_EQ(fraction, res_float);
}

TEST(simple_type, fractional_d) {
    double fraction = 5.5;
    auto res_double = sum_all(fraction);
    EXPECT_EQ(fraction, res_double);
}

TEST(simple_type, string) {
    std::string str = "abc";
    auto res = sum_all(str);
    EXPECT_EQ(str, res);
}

TEST(container_1arg, vector) {
    std::vector<int> v{1, 2, 3};
    auto test_res = 6;
    auto res = sum_all(v);
    EXPECT_EQ(test_res, res);
    std::vector<double> v1{1.5, 2.5, 3.5};
    auto test_res1 = 7.5;
    auto res1 = sum_all(v1);
    EXPECT_EQ(test_res1, res1);
    std::vector<std::string> v2{"Hello", ", ", "my", " friend"};
    auto test_res2 = "Hello, my friend";
    auto res2 = sum_all(v2);
    EXPECT_EQ(test_res2, res2);
}


TEST(container_1arg, set) {
    std::set<int> v{1, 2, 3};
    auto test_res = 6;
    auto res = sum_all(v);
    EXPECT_EQ(test_res, res);
    std::set<double> v1{1.5, 2.5, 3.5};
    auto test_res1 = 7.5;
    auto res1 = sum_all(v1);
    EXPECT_EQ(test_res1, res1);
    std::set<std::string> v2{"a", "b", "c", "d"};
    auto test_res2 = "abcd";
    auto res2 = sum_all(v2);
    EXPECT_EQ(test_res2, res2);
}

TEST(container_1arg, u_set) {
    std::unordered_set<int> v{1, 2, 3};
    auto test_res = 6;
    auto res = sum_all(v);
    EXPECT_EQ(test_res, res);
    std::unordered_set<double> v1{1.5, 2.5, 3.5};
    auto test_res1 = 7.5;
    auto res1 = sum_all(v1);
    EXPECT_EQ(test_res1, res1);
    std::unordered_set<std::string> v2{"a", "b", "c"};
    auto test_res2 = "abc";
    auto test_res3 = "acb";
    auto test_res4 = "bac";
    auto test_res5 = "bca";
    auto test_res6 = "cab";
    auto test_res7 = "cba";
    auto res2 = sum_all(v2);
    if (res2 == test_res2 || res2 == test_res3 || res2 == test_res4
        || res2 == test_res5 || res2 == test_res6 || res2 == test_res7) {
        SUCCEED();
    } else
        ADD_FAILURE();
}

TEST(container_1arg_char, vector) {
    std::vector<char> v{'a', 'b', 'c'};
    auto test_res = "abc";
    auto res = sum_all(v);
    EXPECT_EQ(test_res, res);
}

TEST(container_1arg_char, set) {
    std::set<char> v{'a', 'b', 'c'};
    auto test_res = "abc";
    auto res = sum_all(v);
    EXPECT_EQ(test_res, res);
}

TEST(container_1arg_char, map) {
    std::map<int, char> v{{1, 'a'},
                          {2, 'b'},
                          {3, 'c'}};
    auto test_res = "abc";
    auto res = sum_all(v);
    EXPECT_EQ(test_res, res);
}

TEST(container_2arg, map) {
    std::map<int, int> v{{1, 1},
                         {2, 2},
                         {3, 3}};
    auto test_res = 6;
    auto res = sum_all(v);
    EXPECT_EQ(test_res, res);
    std::map<int, double> v1{{1, 1.5},
                             {2, 2.5},
                             {3, 3.5}};
    auto test_res1 = 7.5;
    auto res1 = sum_all(v1);
    EXPECT_EQ(test_res1, res1);
    std::map<int, std::string> v2{{1, "a"},
                                  {2, "b"},
                                  {3, "c"},
                                  {4, "d"}};
    auto test_res2 = "abcd";
    auto res2 = sum_all(v2);
    EXPECT_EQ(test_res2, res2);
}

TEST(container_2arg, u_map) {
    std::unordered_map<int, int> v{{1, 1},
                                   {2, 2},
                                   {3, 3}};
    auto test_res = 6;
    auto res = sum_all(v);
    EXPECT_EQ(test_res, res);
    std::unordered_map<int, double> v1{{1, 1.5},
                                       {2, 2.5},
                                       {3, 3.5}};
    auto test_res1 = 7.5;
    auto res1 = sum_all(v1);
    EXPECT_EQ(test_res1, res1);
    std::unordered_map<int, std::string> v2{{1, "a"},
                                            {2, "b"},
                                            {3, "c"}};
    auto test_res2 = "abc";
    auto test_res3 = "acb";
    auto test_res4 = "bac";
    auto test_res5 = "bca";
    auto test_res6 = "cab";
    auto test_res7 = "cba";
    auto res2 = sum_all(v2);
    if (res2 == test_res2 || res2 == test_res3 || res2 == test_res4
        || res2 == test_res5 || res2 == test_res6 || res2 == test_res7) {
        SUCCEED();
    } else
        ADD_FAILURE();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}