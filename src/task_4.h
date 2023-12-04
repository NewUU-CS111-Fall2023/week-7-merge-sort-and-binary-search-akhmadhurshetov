// 
// Author: Axmad Xurshetov
// Date: 04.12.2023
// Name: task 4
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct HeapNode {
    int val, r, c;
    HeapNode(int value, int row, int col) : val(value), r(row), c(col) {}
};

struct compare {
    bool operator()(const HeapNode& a, const HeapNode& b) {
        return a.val > b.val;
    }
};

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    priority_queue<HeapNode, vector<HeapNode>, compare> minHeap;

    // Insert the first element of each row
    for (int i = 0; i < n; i++) {
        minHeap.push(HeapNode(matrix[i][0], i, 0));
    }

    // Extract elements from the heap k times
    for (int i = 0; i < k - 1; i++) {
        HeapNode node = minHeap.top();
        minHeap.pop();

        // Insert the next element from the same row
        if (node.c < n - 1) {
            minHeap.push(HeapNode(matrix[node.r][node.c + 1], node.r, node.c + 1));
        }
    }

    return minHeap.top().val;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << kthSmallest(matrix, k) << endl;
    return 0;
}
