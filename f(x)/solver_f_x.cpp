#include "solver_f_x.hpp"

Strategy::~Strategy() {};

double Dichotomy::DichotomyMethod(double a, double b, double err, double (*f)(double x)) {
    if (f(a) == 0) return a;
    if (f(b) == 0) return b;
    double middle = (a + b) / 2;
    double value = f(middle);
    double currentError = (b - a) / 2;
    if (currentError < err)
        return middle;
    else {
        if (value * f(a) <= 0) {
            return DichotomyMethod(a, middle, err, f);
        } else {
            return DichotomyMethod(middle, b, err, f);
        }
    }
}

double Dichotomy::solve(double a, double b, double err, double f(double x), double df(double x)) {
    return DichotomyMethod(a, b, err, f);
}


double Secant::SecantMethod(double a, double b, double err, double (*f)(double x)) {
    if (f(a) == 0) return a;
    if (f(b) == 0) return b;
    double x1 = a;
    double x2 = b;
    while (fabs(x2 - x1) > err) {
        x1 = x2 - (x2 - x1) * (f(x2) / (f(x2) - f(x1)));
        x2 = x1 + (x1 - x2) * (f(x1) / (f(x1) - f(x2)));
    }
    return x2;
}

double Secant::solve(double a, double b, double err, double f(double x), double df(double x)) {
        return SecantMethod(a, b, err, f);
}


double NewtonMethod::NewtonSolver(double err, double x, double f(double x), double df(double x)) {
    if (f(x) == 0) return x;
    else {
        double value = f(x) / df(x);
        double currentError = fabs((x - f(x) / df(x)) - x);
        if (currentError < err) {
            return x;
        } else {
            return NewtonSolver(err, x - value, f, df);
        }
    }
}

double NewtonMethod::solve(double a, double b, double err, double f(double x), double df(double x)) {
    return NewtonSolver(err, (a + b) / 2, f, df);
}


double Solver::useStrategy(double a, double b, double err, double f(double x), double df(double x)){
    if (*f == nullptr) {
        throw "Function no found ";
    } else if (f(a) == f(b)) {
        throw "Invalid parameters";
    } else {
        return operation->solve(a, b, err, f, df);
    }

}



