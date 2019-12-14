#include <include/gtest/gtest.h>
#include "../solver_f_x.hpp"


TEST(decide_x_in_quadra_minus_two, dichotomy) {
    Solver customClient;
    auto f = [](double x) { return pow(x, 2) - 2; };
    auto df = [](double x) { return 2 * pow(x, 1); };
    double a = 0.1, b = 5, err = 0.000001;
    auto accuracy = 10 * err;
    std::shared_ptr<Dichotomy> dichotomy = std::make_shared<Dichotomy>();
    customClient.setStrategy(dichotomy);
    double solve = customClient.useStrategy(a, b, err, f, df);
    EXPECT_LE((-1) * accuracy, f(solve));
    EXPECT_GE(accuracy, f(solve));
}

TEST(decide_x_in_quadra_minus_two, secant) {
    Solver customClient;
    auto f = [](double x) { return pow(x, 2) - 2; };
    auto df = [](double x) { return 2 * pow(x, 1); };
    double a = 0.1, b = 5, err = 0.000001;
    auto accuracy = 10 * err;
    std::shared_ptr<Secant> secant = std::make_shared<Secant>();
    customClient.setStrategy(secant);
    double solve = customClient.useStrategy(a, b, err, f, df);
    EXPECT_LE((-1) * accuracy, f(solve));
    EXPECT_GE(accuracy, f(solve));
}

TEST(decide_x_in_quadra_minus_two, newton_method) {
    Solver customClient;
    auto f = [](double x) { return pow(x, 2) - 2; };
    auto df = [](double x) { return 2 * pow(x, 1); };
    double a = 0.1, b = 5, err = 0.000001;
    auto accuracy = 10 * err;
    std::shared_ptr<NewtonMethod> newton = std::make_shared<NewtonMethod>();
    customClient.setStrategy(newton);
    double solve = customClient.useStrategy(a, b, err, f, df);
    EXPECT_LE((-1) * accuracy, f(solve));
    EXPECT_GE(accuracy, f(solve));
}

TEST(decide_x_in_cube, dichotomy) {
    Solver customClient;
    auto f = [](double x) { return pow(x, 3); };
    auto df = [](double x) { return 3 * pow(x, 2); };
    double a = -5, b = 5, err = 0.000001;
    auto accuracy = 10 * err;
    std::shared_ptr<Dichotomy> dichotomy = std::make_shared<Dichotomy>();
    customClient.setStrategy(dichotomy);
    double solve = customClient.useStrategy(a, b, err, f, df);
    EXPECT_LE((-1) * accuracy, f(solve));
    EXPECT_GE(accuracy, f(solve));
}

TEST(decide_x_in_cube, secant) {
    Solver customClient;
    auto f = [](double x) { return pow(x, 3); };
    auto df = [](double x) { return 3 * pow(x, 2); };
    double a = -5, b = 5, err = 0.000001;
    auto accuracy = 10 * err;
    std::shared_ptr<Secant> secant = std::make_shared<Secant>();
    customClient.setStrategy(secant);
    double solve = customClient.useStrategy(a, b, err, f, df);
    EXPECT_LE((-1) * accuracy, f(solve));
    EXPECT_GE(accuracy, f(solve));
}

TEST(decide_x_in_cube, newton_method) {
    Solver customClient;
    auto f = [](double x) { return pow(x, 3); };
    auto df = [](double x) { return 3 * pow(x, 2); };
    double a = -5, b = 5, err = 0.000001;
    auto accuracy = 10 * err;
    std::shared_ptr<NewtonMethod> newton = std::make_shared<NewtonMethod>();
    customClient.setStrategy(newton);
    double solve = customClient.useStrategy(a, b, err, f, df);
    EXPECT_LE((-1) * accuracy, f(solve));
    EXPECT_GE(accuracy, f(solve));
}


TEST(decide_2_ways, dichotomy_secant) {
    Solver customClient;
    auto f = [](double x) { return pow(x, 3); };
    auto df = [](double x) { return 3 * pow(x, 2); };
    double a = -5, b = 5, err = 0.000001;
    auto accuracy = 10 * err;
    std::shared_ptr<Dichotomy> dichotomy = std::make_shared<Dichotomy>();
    customClient.setStrategy(dichotomy);
    double solve = customClient.useStrategy(a, b, err, f, df);
    EXPECT_LE((-1) * accuracy, f(solve));
    EXPECT_GE(accuracy, f(solve));
    std::shared_ptr<Secant> secant = std::make_shared<Secant>();
    customClient.setStrategy(secant);
    solve = customClient.useStrategy(a, b, err, f, df);
    EXPECT_LE((-1) * accuracy, f(solve));
    EXPECT_GE(accuracy, f(solve));
}

TEST(decide_2_ways, dichotomy_newton) {
    Solver customClient;
    auto f = [](double x) { return pow(x, 3); };
    auto df = [](double x) { return 3 * pow(x, 2); };
    double a = -5, b = 5, err = 0.000001;
    auto accuracy = 10 * err;
    std::shared_ptr<Dichotomy> dichotomy = std::make_shared<Dichotomy>();
    customClient.setStrategy(dichotomy);
    double solve = customClient.useStrategy(a, b, err, f, df);
    EXPECT_LE((-1) * accuracy, f(solve));
    EXPECT_GE(accuracy, f(solve));
    std::shared_ptr<NewtonMethod> newton = std::make_shared<NewtonMethod>();
    customClient.setStrategy(newton);
    solve = customClient.useStrategy(a, b, err, f, df);
    EXPECT_LE((-1) * accuracy, f(solve));
    EXPECT_GE(accuracy, f(solve));
}

TEST(decide_2_ways, secant_newton) {
    Solver customClient;
    auto f = [](double x) { return pow(x, 3); };
    auto df = [](double x) { return 3 * pow(x, 2); };
    double a = -5, b = 5, err = 0.000001;
    auto accuracy = 10 * err;
    std::shared_ptr<Secant> secant = std::make_shared<Secant>();
    customClient.setStrategy(secant);
    double solve = customClient.useStrategy(a, b, err, f, df);
    EXPECT_LE((-1) * accuracy, f(solve));
    EXPECT_GE(accuracy, f(solve));

    std::shared_ptr<NewtonMethod> newton = std::make_shared<NewtonMethod>();
    customClient.setStrategy(newton);
    solve = customClient.useStrategy(a, b, err, f, df);
    EXPECT_LE((-1) * accuracy, f(solve));
    EXPECT_GE(accuracy, f(solve));
}

TEST(decide_3_ways, dichotomy_secant_newton) {
    Solver customClient;
    auto f = [](double x) { return pow(x, 5); };
    auto df = [](double x) { return 5 * pow(x, 4); };
    double a = -5, b = 5, err = 0.000001;
    auto accuracy = 10 * err;
    std::shared_ptr<Dichotomy> dichotomy = std::make_shared<Dichotomy>();
    customClient.setStrategy(dichotomy);
    double solve = customClient.useStrategy(a, b, err, f, df);
    EXPECT_LE((-1) * accuracy, f(solve));
    EXPECT_GE(accuracy, f(solve));

    std::shared_ptr<Secant> secant = std::make_shared<Secant>();
    customClient.setStrategy(secant);
    solve = customClient.useStrategy(a, b, err, f, df);
    EXPECT_LE((-1) * accuracy, f(solve));
    EXPECT_GE(accuracy, f(solve));

    std::shared_ptr<NewtonMethod> newton = std::make_shared<NewtonMethod>();
    customClient.setStrategy(newton);
    solve = customClient.useStrategy(a, b, err, f, df);
    EXPECT_LE((-1) * accuracy, f(solve));
    EXPECT_GE(accuracy, f(solve));
}

TEST(f_null, dichotomy) {
    try {
        Solver customClient;
        auto f = [](double x) { return pow(x, 5); };
        auto df = [](double x) { return 5 * pow(x, 4); };
        double a = -5, b = 5, err = 0.000001;
        double solve;
        auto accuracy = 10 * err;
        std::shared_ptr<Dichotomy> dichotomy = std::make_shared<Dichotomy>();
        customClient.setStrategy(dichotomy);
        solve = customClient.useStrategy(a, b, err, nullptr, df);
        EXPECT_LE((-1) * accuracy, f(solve));
        EXPECT_GE(accuracy, f(solve));
    } catch (const char *a) {
        std::cout << a << std::endl;
    }
}

TEST(f_null, secant) {
    try {
        Solver customClient;
        auto f = [](double x) { return pow(x, 5); };
        auto df = [](double x) { return 5 * pow(x, 4); };
        double a = -5, b = 5, err = 0.000001;
        double solve;
        auto accuracy = 10 * err;
        std::shared_ptr<Secant> secant = std::make_shared<Secant>();
        customClient.setStrategy(secant);
        solve = customClient.useStrategy(a, b, err, nullptr, df);
        EXPECT_LE((-1) * accuracy, f(solve));
        EXPECT_GE(accuracy, f(solve));
    } catch (const char *a) {
        std::cout << a << std::endl;
    }
}

TEST(f_null, newton) {
    try {
        Solver customClient;
        auto f = [](double x) { return pow(x, 5); };
        auto df = [](double x) { return 5 * pow(x, 4); };
        double a = -5, b = 5, err = 0.000001;
        double solve;
        auto accuracy = 10 * err;
        std::shared_ptr<NewtonMethod> newton = std::make_shared<NewtonMethod>();
        customClient.setStrategy(newton);
        solve = customClient.useStrategy(a, b, err, nullptr, df);
        EXPECT_LE((-1) * accuracy, f(solve));
        EXPECT_GE(accuracy, f(solve));
    } catch (const char *a) {
        std::cout << a << std::endl;
    }
}


TEST(invalid_a_b, dichotomy) {
    try {
        Solver customClient;
        auto f = [](double x) { return pow(x, 4); };
        auto df = [](double x) { return 4 * pow(x, 3); };
        double a = -5, b = 5, err = 0.000001;
        auto accuracy = 10 * err;
        std::shared_ptr<Dichotomy> dichotomy = std::make_shared<Dichotomy>();
        customClient.setStrategy(dichotomy);
        double solve = customClient.useStrategy(a, b, err, f, df);
        EXPECT_LE((-1) * accuracy, f(solve));
        EXPECT_GE(accuracy, f(solve));
    } catch (const char *a) {
        std::cout << a << std::endl;
    }
}

TEST(invalid_a_b, secant) {
    try {
        Solver customClient;
        auto f = [](double x) { return pow(x, 4); };
        auto df = [](double x) { return 4 * pow(x, 3); };
        double a = -5, b = 5, err = 0.000001;
        auto accuracy = 10 * err;
        std::shared_ptr<Secant> secant = std::make_shared<Secant>();
        customClient.setStrategy(secant);
        double solve = customClient.useStrategy(a, b, err, f, df);
        EXPECT_LE((-1) * accuracy, f(solve));
        EXPECT_GE(accuracy, f(solve));
    } catch (const char *a) {
        std::cout << a << std::endl;
    }
}

TEST(invalid_a_b, newton) {
    try {
        Solver customClient;
        auto f = [](double x) { return pow(x, 4); };
        auto df = [](double x) { return 4 * pow(x, 3); };
        double a = -5, b = 5, err = 0.000001;
        auto accuracy = 10 * err;
        std::shared_ptr<NewtonMethod> newton = std::make_shared<NewtonMethod>();
        customClient.setStrategy(newton);
        double solve = customClient.useStrategy(a, b, err, f, df);
        EXPECT_LE((-1) * accuracy, f(solve));
        EXPECT_GE(accuracy, f(solve));
    } catch (const char *a) {
        std::cout << a << std::endl;
    }
}


TEST(f3, dichotomy) {
    Solver customClient;
    auto f = [](double x) { return pow(x, 2) - 2; };
    auto df = [](double x) { return 2 * pow(x, 1); };
    double a = 1.01, b = 5, err = 0.000001;
    auto accuracy = 10 * err;

    std::shared_ptr<Dichotomy> dichotomy = std::make_shared<Dichotomy>();
    customClient.setStrategy(dichotomy);
    double solve = customClient.useStrategy(a, b, err, f, df);
    EXPECT_LE((-1) * accuracy, f(solve));
    EXPECT_GE(accuracy, f(solve));

    auto f1 = [](double x) { return pow(x, 5) - 2; };
    auto df1 = [](double x) { return 5 * pow(x, 4); };
    solve = customClient.useStrategy(a, b, err, f1, df1);
    EXPECT_LE((-1) * accuracy, f1(solve));
    EXPECT_GE(accuracy, f1(solve));

    auto f2 = [](double x) { return pow(x, 3) - 2; };
    auto df2 = [](double x) { return 3 * pow(x, 2); };
    solve = customClient.useStrategy(a, b, err, f2, df2);
    EXPECT_LE((-1) * accuracy, f2(solve));
    EXPECT_GE(accuracy, f2(solve));
}

TEST(f3, secant) {
    Solver customClient;
    auto f = [](double x) { return pow(x, 2) - 2; };
    auto df = [](double x) { return 2 * pow(x, 1); };
    double a = 1.01, b = 5, err = 0.000001;
    auto accuracy = 10 * err;

    std::shared_ptr<Secant> secant = std::make_shared<Secant>();
    customClient.setStrategy(secant);
    double solve = customClient.useStrategy(a, b, err, f, df);
    EXPECT_LE((-1) * accuracy, f(solve));
    EXPECT_GE(accuracy, f(solve));

    auto f1 = [](double x) { return pow(x, 5) - 2; };
    auto df1 = [](double x) { return 5 * pow(x, 4); };
    solve = customClient.useStrategy(a, b, err, f1, df1);
    EXPECT_LE((-1) * accuracy, f1(solve));
    EXPECT_GE(accuracy, f1(solve));

    auto f2 = [](double x) { return pow(x, 3) - 2; };
    auto df2 = [](double x) { return 3 * pow(x, 2); };
    solve = customClient.useStrategy(a, b, err, f2, df2);
    EXPECT_LE((-1) * accuracy, f2(solve));
    EXPECT_GE(accuracy, f2(solve));
}

TEST(f3, newton) {
    Solver customClient;
    auto f = [](double x) { return pow(x, 2) - 2; };
    auto df = [](double x) { return 2 * pow(x, 1); };
    double a = 1.01, b = 5, err = 0.000001;
    auto accuracy = 10 * err;

    std::shared_ptr<NewtonMethod> newton = std::make_shared<NewtonMethod>();
    customClient.setStrategy(newton);
    double solve = customClient.useStrategy(a, b, err, f, df);
    EXPECT_LE((-1) * accuracy, f(solve));
    EXPECT_GE(accuracy, f(solve));

    auto f1 = [](double x) { return pow(x, 5) - 2; };
    auto df1 = [](double x) { return 5 * pow(x, 4); };
    solve = customClient.useStrategy(a, b, err, f1, df1);
    EXPECT_LE((-1) * accuracy, f1(solve));
    EXPECT_GE(accuracy, f1(solve));

    auto f2 = [](double x) { return pow(x, 3) - 2; };
    auto df2 = [](double x) { return 3 * pow(x, 2); };
    solve = customClient.useStrategy(a, b, err, f2, df2);
    EXPECT_LE((-1) * accuracy, f2(solve));
    EXPECT_GE(accuracy, f2(solve));
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}