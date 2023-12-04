#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> findMissingNumbers(int n, const vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end());
    vector<int> missingNumbers;

    for (int i = 0; i <= n; i++) {
        if (numSet.find(i) == numSet.end()) {
            missingNumbers.push_back(i);
        }
    }

    return missingNumbers;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> missing = findMissingNumbers(n, nums);
    for (int num : missing) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
