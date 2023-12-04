#include <iostream>
#include <vector>

using namespace std;

int findKthPositive(const vector<int>& arr, int k) {
    int missingCount = 0, lastNumChecked = 0;
    size_t arrIndex = 0;

    while (missingCount < k) {
        lastNumChecked++;
        if (arrIndex < arr.size() && arr[arrIndex] == lastNumChecked) {
            // The current number is in the array, move to the next number in the array
            arrIndex++;
        } else {
            // The current number is missing in the array
            missingCount++;
        }
    }

    return lastNumChecked;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << findKthPositive(arr, k) << endl;

    return 0;
}
