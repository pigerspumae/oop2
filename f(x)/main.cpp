#include <iostream>
#include "solver_f_x.hpp"

int main() {
    Solver customClient;
    auto f = [](double x) { return pow(x, 2) - 2; };
    auto df = [](double x) { return 2 * pow(x, 1); };
    double a = 1.01, b = 5, err = 0.000001;
    auto accuracy = 10 * err;
    std::shared_ptr<Dichotomy> dichotomy = std::make_shared<Dichotomy>();
    customClient.setStrategy(dichotomy);
    double solve = customClient.useStrategy(a, b, err, f, df);
    std::cout << ((-1) * accuracy) << "    " << (solve)<<  "    " <<f(solve) << "    " << (accuracy) << std::endl;

    auto f1 = [](double x) { return pow(x, 5) - 2; };
    auto df1 = [](double x) { return 5 * pow(x, 4); };
    solve = customClient.useStrategy(a, b, err, f1, df1);
    std::cout << ((-1) * accuracy) << "    " << (solve)<< "    " << f1(solve) << "    " << (accuracy) << std::endl;

    auto f2 = [](double x) { return pow(x, 3) -2; };
    auto df2 = [](double x) { return 3 * pow(x, 2); };
    solve = customClient.useStrategy(a, b, err, f2, df2);
    std::cout << ((-1) * accuracy) << "    " << (solve)<< "    " << f2(solve) << "    " << (accuracy) << std::endl;
    return 0;
}