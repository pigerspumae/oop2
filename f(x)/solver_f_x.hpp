#ifndef F_X_SOLVER_F_X_HPP
#define F_X_SOLVER_F_X_HPP


#include <iostream>
#include <cmath>
#include <memory>

class Strategy {
public:
    virtual double solve(double a, double b, double err, double f(double x), double df(double x)) = 0;

    virtual ~Strategy() = 0;
};

class Dichotomy : public Strategy {
public:
    double DichotomyMethod(double a, double b, double err, double (*f)(double x));

    double solve(double a, double b, double err, double f(double x), double df(double x)) override;

};

class Secant : public Strategy {
public:
    double SecantMethod(double a, double b, double err, double (*f)(double x));

    double solve(double a, double b, double err, double f(double x), double df(double x)) override;
};

class NewtonMethod : public Strategy {
public:
    double NewtonSolver(double err, double x, double f(double x), double df(double x));

    double solve(double a, double b, double err, double f(double x), double df(double x)) override;
};

class Context {
protected:
    std::shared_ptr<Strategy> operation = nullptr;

public:
    virtual ~Context() {}

    virtual double useStrategy(double a, double b, double err, double f(double x), double df(double x)) = 0;

    virtual void setStrategy(std::shared_ptr<Strategy> o) = 0;
};

class Solver : public Context {
public:
    double useStrategy(double a, double b, double err, double f(double x), double df(double x)) override;

    void setStrategy(std::shared_ptr<Strategy> o) override {

        operation = o;
    }
};

#endif //F_X_SOLVER_F_X_HPP
