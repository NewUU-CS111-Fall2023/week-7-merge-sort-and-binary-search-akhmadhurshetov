#include <iostream>
#include <vector>

using namespace std;

int kthFactor(int n, int k) {
    vector<int> factors;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            factors.push_back(i);
        }
    }
    if (k <= factors.size()) {
        return factors[k - 1];
    } else {
        return -1;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << kthFactor(n, k) << endl;
    return 0;
}
