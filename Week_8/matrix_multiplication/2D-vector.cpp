// 2D-vector.cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> grid(2, vector<int>(3));  // 2 rows, 3 columns each
    grid[1][2] = 99;

    for (const auto& row : grid) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }

    for (size_t i = 0; i < grid.size(); ++i) {
        for (size_t j = 0; j < grid.at(i).size(); ++j) {
            cout << grid.at(i).at(j) << " ";
            // cout << grid[i][j] << " ";  // this works too, just no bounds check
        }
        cout << "\n";
    }

    return 0;
}
