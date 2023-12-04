
// 
// Author: Axmad Xurshetov
// Date: 04.12.2023
// Name: task 3
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> mergeArrays(vector<int>& A, vector<int>& B) {
    // Merging two sorted arrays in non-increasing order
    vector<int> result;
    int i = 0, j = 0;
    while (i < A.size() && j < B.size()) {
        if (A[i] > B[j]) {
            result.push_back(A[i++]);
        } else {
            result.push_back(B[j++]);
        }
    }
    // Adding remaining elements
    while (i < A.size()) {
        result.push_back(A[i++]);
    }
    while (j < B.size()) {
        result.push_back(B[j++]);
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A(N), B(M);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int j = 0; j < M; j++) {
            cin >> B[j];
        }
        vector<int> merged = mergeArrays(A, B);
        for (int k = 0; k < merged.size(); k++) {
            cout << merged[k] << " ";
        }
        cout << endl;
    }
    return 0;
}
