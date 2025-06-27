//2D-multi-threading.cpp
#include <iostream>
#include <vector>
#include <thread>

using namespace std;

// Thread function: add one row from A and B into C
void addRow(const vector<vector<int>>& A,
            const vector<vector<int>>& B,
            vector<vector<int>>& C,
            int row) {
    for (size_t col = 0; col < A[0].size(); ++col) {
        C[row][col] = A[row][col] + B[row][col];
    }
}
