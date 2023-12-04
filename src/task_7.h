#include <iostream>

using namespace std;

long long recursivePow(int x, int n) {
    if (n == 0) return 1; // Base case
    if (n % 2 == 0) {
        // Optimization for even powers
        long long halfPow = recursivePow(x, n / 2);
        return halfPow * halfPow;
    } else {
        // Recursive case
        return x * recursivePow(x, n - 1);
    }
}

int main() {
    int x;
    cin >> x;
    cout << recursivePow(x, 2) << endl;  // As per the problem statement, n is always 2
    return 0;
}
