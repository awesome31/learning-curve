#include<iostream>
using namespace std;

int pascalsTriangleNcr(int n, int r) {
    if (r == 0 || r == n) return 1;

    return pascalsTriangleNcr(n - 1, r - 1) + pascalsTriangleNcr(n - 1, r);
}

int main() {
    cout << pascalsTriangleNcr(5, 2) << endl;

    return 0;
}
