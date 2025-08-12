#include <bits/stdc++.h>
#define EPSILON 0.001
using namespace std;

double func(double x) {
    return x*x*x - x - 2;
}

double derivFunc(double x) {
    return 3*x*x - 1;
}

void newtonRaphson(double x) {
    double h = func(x) / derivFunc(x);
    while (abs(h) >= EPSILON) {
        h = func(x) / derivFunc(x);
        cout << "x = " << x << ", f(x) = " << func(x) << ", h = " << h << endl;
        x = x - h;
    }
    cout << "The value of  root is : " << x << endl;
}

int main() {
    double x0 = 1.5;
    newtonRaphson(x0);
    return 0;
}