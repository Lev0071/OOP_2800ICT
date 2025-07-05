#include <iostream>
#include <vector>
#include <thread>
#include <random>
#include <chrono>
#include <iomanip>  // Added for std::fixed and std::setprecision

using namespace std;

void fillRandom(vector<vector<int>>& mat, int maxVal = 999);






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

// g++ -std=c++17 run_wa8.cpp -o wa8 -pthread