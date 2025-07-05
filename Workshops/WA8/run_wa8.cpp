#include <iostream>
#include <vector>
#include <thread>
#include <random>
#include <chrono>
#include <iomanip>  // Added for std::fixed and std::setprecision

using namespace std;
// //---------------------------------------------------------------
// vector<vector<int>> A(m, vector<int>(n));

// // Get dimensions
// size_t rows = A.size();       // m
// size_t cols = A[0].size();    // n
// //---------------------------------------------------------------

void fillRandom(vector<vector<int>>& mat, int maxVal = 999);

void matrixProduct(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C,size_t startRow, size_t endRow){
    size_t n = A[0].size();  // Columns of A
    size_t p = B[0].size();  // Columns of B
    for (i = startRow; i < endRow; ++i)
        for (j = 0; j < p; ++j)
            for (k = 0; k < n; ++k)
                C[i][j] += A[i][k] * B[k][j];
}

// ================ Note: Do not modify the code provided below. ================
int main() {
    int m = 1000, n = 1000, p = 1000;
    int numThreads = 2;

    vector<vector<int>> A(m, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(p));
    vector<vector<int>> C1(m, vector<int>(p, 0));
    vector<vector<int>> C2(m, vector<int>(p, 0));

    fillRandom(A);
    fillRandom(B);

    // Single-threaded
    auto t1 = chrono::high_resolution_clock::now();
    customOpSingle(A, B, C1);
    auto t2 = chrono::high_resolution_clock::now();
    auto durationSingle = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();
    cout << "[Single-threaded] Time: " << durationSingle << " ms\n";

    // Multi-threaded
    t1 = chrono::high_resolution_clock::now();
    customOpMulti(A, B, C2, numThreads);
    t2 = chrono::high_resolution_clock::now();
    auto durationMulti = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();
    cout << "[Multi-threaded (" << numThreads << " threads)] Time: " << durationMulti << " ms\n";

    // Validate result
    bool match = true;
    for (int i = 0; i < m && match; ++i)
        for (int j = 0; j < p && match; ++j)
            if (C1[i][j] != C2[i][j])
                match = false;

    cout << "Result: " << (match ? "Match" : "Mismatch") << endl;

    // Speedup calculation
    double speedup = static_cast<double>(durationSingle) / durationMulti;
    cout << "Speedup (Single-threaded time / Multi-threaded time): " << fixed << setprecision(2) << speedup << "x" << endl;

    return 0;
}

// Fill a matrix with random integers
void fillRandom(vector<vector<int>>& mat, int maxVal) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, maxVal);
    for (auto& row : mat)
        for (auto& val : row)
            val = dist(gen);
}

// ================ Note: Do not modify the code provided above. ================

// EXPLANATION
// For matrix multiplication, since [A(m×n)] × [B(n×p)] = C(m×p) iff n == n → true,
// then instead of dividing the mandatory dimension (which is n) by the number of threads, I should divide the output rows dimension (which is m) by the number of threads to get the chunk size.
// This way, each thread works on its chunk-size amount of rows in the output matrix C.
// Each chunk is calculated independently and combined together naturally, since the rows don’t overlap.

// We will try to adapt:
// size_t chunkSize = m / numThreads;

// for (int i = 0; i < numThreads; ++i) {
//     size_t startRow = i * chunkSize;
//     size_t endRow = (i == numThreads - 1) ? m : startRow + chunkSize;

//     // Launch thread to do rows [startRow, endRow)
// }

// with:

//     for (int i = 0; i < m; ++i) { // over rows of C (rows of A)
//         for (int j = 0; j < p; ++j) { // over cols of C (cols of B)
//             for (int k = 0; k < n; ++k) { // over shared dimension (A cols / B rows)
//                 C[i][j] += A[i][k] * B[k][j];
//             }
//         }
//     }
// In single-threaded: i = 0 to m

// In multi-threaded: each thread gets its own slice of rows
// startRow = i * chunkSize
// endRow   = ... (next boundary or m)

// for (int i = startRow; i < endRow; ++i) {
//   ...
// }

// g++ -std=c++17 run_wa8.cpp -o wa8 -pthread

