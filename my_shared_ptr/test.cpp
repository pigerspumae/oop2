#include <include/gtest/gtest.h>
#include "../my_shared_ptr.hpp"


TEST(operator_eq, valid_ptr) {
    int *a = new(int);
    int *b = new(int);
    SharedPTR<int> ptr(a);
    ptr = b;
    EXPECT_EQ(ptr.get(), b);
    EXPECT_EQ(*(get_count(ptr)), 1);
}

TEST(operator_eq, same_ptr) {
    int *a = new(int);
    SharedPTR<int> ptr(a);
    ptr = a;
    EXPECT_EQ(ptr.get(), a);
    EXPECT_EQ(*(get_count(ptr)), 1);
}


TEST(operator_eq, null_ptr) {
    int *a = new(int);
    *a = 1;
    SharedPTR<int> ptr(a);
    ptr = nullptr;
    EXPECT_EQ(ptr.get(), nullptr);
    EXPECT_EQ(*(get_count(ptr)), 1);
}

TEST(operator_eq, valid_constr) {
    int *a = new(int);
    *a = 1;
    SharedPTR<int> ptr(a);
    SharedPTR<int> ptr2(ptr);
    EXPECT_EQ(ptr.get(), ptr2.get());
    EXPECT_EQ(*(get_count(ptr)), 2);
    EXPECT_EQ(*(get_count(ptr2)), 2);
    EXPECT_EQ(ptr.get(), a);
    EXPECT_EQ(ptr2.get(), a);
}

TEST(operator_eq, null_constr) {
    SharedPTR<int> ptr;
    SharedPTR<int> ptr2(ptr);
    EXPECT_EQ(ptr.get(), nullptr);
    EXPECT_EQ(ptr2.get(), nullptr);
    EXPECT_EQ((get_count(ptr)), nullptr);
    EXPECT_EQ((get_count(ptr2)), nullptr);
}

TEST(operator_sh_PTR, valid) {
    int *a = new(int);
    *a = 1;
    SharedPTR<int> ptr(a);
    EXPECT_EQ(*ptr, *a);
    EXPECT_EQ(*(get_count(ptr)), 1);
}

TEST(get, valid) {
    int *a = new(int);
    *a = 1;
    SharedPTR<int> ptr(a);
    EXPECT_EQ(ptr.get(), a);
    EXPECT_EQ(*(get_count(ptr)), 1);
}

TEST(get, default) {
    SharedPTR<int> ptr;
    EXPECT_EQ(ptr.get(), nullptr);
}

TEST(operator_bool, TRUE) {
    int *a = new(int);
    *a = 1;
    SharedPTR<int> ptr(a);
    EXPECT_TRUE(ptr);
    EXPECT_EQ(*(get_count(ptr)), 1);
}

TEST(operator_bool, FALSE) {
    SharedPTR<int> ptr;
    EXPECT_FALSE(ptr);
    EXPECT_EQ(get_count(ptr), nullptr);
}

TEST(release, valid) {
    int *a = new(int);
    *a = 1;
    auto add = a;
    SharedPTR<int> ptr(a);
    EXPECT_EQ(*(get_count(ptr)), 1);
    ptr.release();
    EXPECT_EQ(ptr.get(), nullptr);
    EXPECT_EQ(get_count(ptr), nullptr);
    EXPECT_EQ(a, add);
    EXPECT_EQ(*a, 1);
}


TEST(release, empty) {
    SharedPTR<int> ptr;
    ptr.release();
    EXPECT_EQ(ptr.get(), nullptr);
}

TEST(reset, valid) {
    int *a = new(int);
    *a = 1;
    SharedPTR<int> ptr(a);
    ptr.reset();
    EXPECT_EQ(ptr.get(), nullptr);
    EXPECT_EQ(*(get_count(ptr)), 1);
}

TEST(reset, empty) {
    SharedPTR<int> ptr;
    ptr.reset();
    EXPECT_EQ(ptr.get(), nullptr);
    EXPECT_EQ(get_count(ptr), nullptr);
}


TEST(swap, valid) {
    int *a = new(int);
    *a = 1;
    int *b = new(int);
    *b = 2;
    SharedPTR<int> ptr(a);
    SharedPTR<int> ptr2(b);
    ptr.swap(ptr2);
    EXPECT_EQ(*ptr, *b);
    EXPECT_EQ(*(get_count(ptr)), 1);
    EXPECT_EQ(*ptr2, *a);
    EXPECT_EQ(*(get_count(ptr)), 1);
}

TEST(move_semantics, defalt) {
    int *a = new(int);
    SharedPTR<int> ptr(a);
    SharedPTR<int> ptr2(std::move(ptr));
    EXPECT_EQ(ptr.get(), nullptr);
    EXPECT_EQ(get_count(ptr), nullptr);
    EXPECT_EQ(*(get_count(ptr2)), 1);
}

TEST(move_semantics, valid) {
    int *a = new(int);
    *a = 1;
    SharedPTR<int> ptr(a);
    SharedPTR<int> ptr2(std::move(ptr));
    EXPECT_EQ(ptr.get(), nullptr);
    EXPECT_EQ(get_count(ptr), nullptr);
    EXPECT_EQ(ptr2.get(), a);
    EXPECT_EQ(*ptr2.get(), *a);
    EXPECT_EQ(*(get_count(ptr2)), 1);
}

TEST(assignment, empty) {
    SharedPTR<int> ptr;
    SharedPTR<int> ptr2;
    ptr = ptr2;
    EXPECT_EQ(ptr.get(), nullptr);
    EXPECT_EQ(get_count(ptr), nullptr);
}

TEST(assignment, valid) {
    int *a = new(int);
    *a = 1;
    SharedPTR<int> ptr(a);
    int *b = new(int);
    *a = 2;
    SharedPTR<int> ptr2(b);
    ptr = ptr2;
    EXPECT_EQ(ptr.get(), ptr2.get());
    EXPECT_EQ(*get_count(ptr), *get_count(ptr2));
}


TEST(deleter, destructor) {
    struct A {
        bool &destructor_invoked;
        int *arr = new int[20];

        A(bool &destructor_invoked_) : destructor_invoked(destructor_invoked_) {};

        ~A() {
            destructor_invoked = true;
            delete[] arr;
        }
    };

    bool destructor_invoked = false;
    SharedPTR<A> ptr(new A(destructor_invoked));
    EXPECT_FALSE(destructor_invoked);
    ptr.release();
    EXPECT_TRUE(destructor_invoked);
    EXPECT_EQ(ptr.get(), nullptr);
    EXPECT_EQ(get_count(ptr), nullptr);

}


TEST(deleter, destructor1) {
    struct A {
        bool &destructor_invoked;
        std::vector<int>arr = {1, 2,3,4,5};

        A(bool &destructor_invoked_) : destructor_invoked(destructor_invoked_) {};

        ~A() {
            destructor_invoked = true;
            arr.erase(arr.begin(), arr.end());
        }
    };
    bool destructor_invoked = false;
    SharedPTR<A> ptr(new A(destructor_invoked));
    EXPECT_FALSE(destructor_invoked);
    ptr.release();
    EXPECT_TRUE(destructor_invoked);
    EXPECT_EQ(ptr.get(), nullptr);
    EXPECT_EQ(get_count(ptr), nullptr);

}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}





