#include <iostream>
#include <vector>

using namespace std;

pair<int, int> searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return {1, mid}; // Target found
        }
        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return {-1, left}; // Target not found, return insertion position
}

int main() {
    int n, target;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cin >> target;

    pair<int, int> result = searchInsert(nums, target);
    cout << result.first << " " << result.second << endl;

    return 0;
}
