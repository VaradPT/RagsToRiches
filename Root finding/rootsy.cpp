#include <iostream>
#include <cmath>
#include "rootsy.hpp"
using namespace std;
/*
//Bisection
double accept(double x)
{   //Declaring the mathematical function
    std::cout<<"Enter the Type of equation to solve:";
    std::cout<<"A. Quadratic / degree 2 ";
    std::cout<<"B. Cubic / degree 3";
    std::cout<<"C. Other";
     
    // Aiming to accept the function from user.. will be interesting
    //A. method 1. Accept coefficients in one array, powers in another, corelate, calculate .. for any polynomial
    //B. method 2. Accept coefficients .. usual way..  coefficients, powers
}
void bisection(double a, double b, double tol = 1e-6) {
    if (f(a) * f(b) >= 0) {
        cout << "No root in the interval." << endl;
        return;
    }

    double c;
    while ((b - a) >= tol) {
        c = (a + b) / 2;
        if (f(c) == 0.0) break;
        else if (f(c) * f(a) < 0) b = c;
        else a = c;
    }

    cout << "Bisection Method Root: " << c << endl;
}
*/
/*
//Newton Raphson
double df(double x) {
    return 3*x*x - 1;
}

void newtonRaphson(double x0, double tol = 1e-6, int maxIter = 100) {
    double x = x0;
    for (int i = 0; i < maxIter; ++i) {
        double fx = f(x);
        double dfx = df(x);
        if (dfx == 0) {
            cout << "Derivative is zero. Can't continue." << endl;
            return;
        }
        double x1 = x - fx / dfx;
        if (fabs(x1 - x) < tol) {
            cout << "Newton-Raphson Root: " << x1 << endl;
            return;
        }
        x = x1;
    }
    cout << "Did not converge." << endl;
}
*/
//Fixed Point 
double g(double x) {
    return cbrt(x + 2);
}

void fixedPoint(double x0, double tol = 1e-6, int maxIter = 100) {
    double x = x0;
    for (int i = 0; i < maxIter; ++i) {
        double x1 = g(x);
        if (fabs(x1 - x) < tol) {
            cout << "Fixed Point Root: " << x1 << endl;
            return;
        }
        x = x1;
    }
    cout << "Did not converge." << endl;
}







