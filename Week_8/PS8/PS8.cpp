#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <random>
#include <numeric> // for std::accumulate
using namespace std;


int main() {
    const size_t dataSize = 600'000'000; // 500 million
    const int numThreads = 2; // You can adjust this number based on your CPU

    cout << "Generating random data..." << endl;

    // Initialize random number generator
    vector<int> data(dataSize);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 1000);

    for (size_t i = 0; i < dataSize; ++i) {
        data[i] = distrib(gen);
    }

    cout << "Data generation completed." << endl;

    // Single-threaded counting
    cout << "Starting single-threaded counting..." << endl;
    auto start_time = chrono::high_resolution_clock::now();
    size_t evenCountSingle = countEvenSingleThread(data);
    auto end_time = chrono::high_resolution_clock::now();
    
    auto duration_single = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    cout << "[Single-thread] Total even numbers: " << evenCountSingle << endl;
    cout << "[Single-thread] Computation time: " << duration_single << " ms" << endl;

    // Multithreaded counting
    cout << "Starting multithreaded counting with " << numThreads << " threads..." << endl;
    start_time = chrono::high_resolution_clock::now();
    size_t evenCountMulti = countEvenMultiThread(data, numThreads);
    end_time = chrono::high_resolution_clock::now();

    auto duration_multi = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    cout << "[Multi-thread] Total even numbers: " << evenCountMulti << endl;
    cout << "[Multi-thread] Computation time: " << duration_multi << " ms" << endl;

    // Validation
    if (evenCountSingle == evenCountMulti) {
        cout << "Results match" << endl;
    } else {
        cerr << "Results do not match" << endl;
    }

    // Speedup calculation
    double speedup = static_cast<double>(duration_single) / duration_multi;
    cout << "Speedup (Single-threaded time / Multi-threaded time): " << fixed << setprecision(2) << speedup << "x" << endl;

    return 0;
}
