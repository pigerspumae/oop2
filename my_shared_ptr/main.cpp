#include<iostream>
#include"my_shared_ptr.hpp"

class A {
public:
    ~A() { std::cout << "dest A" << std::endl;}
};

int main() {
    {
        SharedPTR<A> shr_ptr = new A();
        SharedPTR<A> shr_ptr2(std::move(shr_ptr));
        SharedPTR<A> shr_ptr3(shr_ptr2);
        SharedPTR<A> shr_ptr4 = std::move(shr_ptr3);
        SharedPTR<A> shr_ptr5 = shr_ptr4;
        shr_ptr5.reset(new A());
        shr_ptr5.swap(shr_ptr2);
    }
    return 0;
}