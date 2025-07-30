/**
 * Taylor series e power x.
 * Using the Horner's method, we can reduce the number of multiplications from n square to n.
 */

#include <iostream>
using namespace std;

static double currentF = 1;
static double currentFSum = 0;

//X: The input and n is the number of iterations.
double taylorSeries(double x, double n) {
    if(n == 0) {
        currentFSum = 1;
        return 1;
    }

    taylorSeries(x, n-1);
    currentF = (x / n) * currentF;
    currentFSum = currentFSum + currentF;

    return currentFSum;
}

double taylorSeriesHornerLoop(double x, double n) {
    double s = 1;

    for(;n > 0; n--) {
        s = 1 + ((x / n) * s);
    }

    return s;
}

double taylorSeriesHorner(double x, double n) {
    static double s = 1;

    if(n == 0) {
        return s;
    }

    s = 1 + ((x / n) * s);
    return taylorSeriesHorner(x, n - 1);
}

int main() {
    cout << taylorSeries(3, 20) << endl;
    cout << taylorSeriesHornerLoop(3, 20) << endl;
    cout << taylorSeriesHorner(3, 30) << endl;
}
