#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <random>
#include <iomanip>
#include <numeric> // for std::accumulate
using namespace std;

void countEven(const vector<int>& data,size_t start,size_t end,size_t& evenCount){
    evenCount = 0;
    for(size_t i=start;i<end;i++){
        if(data[i]%2 == 0 ){evenCount++;}
    }
}

size_t countEvenSingleThread(const vector<int>& data){
    size_t evenCount = 0;
    countEven(data,0,data.size(),evenCount);
    return evenCount;
}

size_t countEvenMultiThread(const vector<int>& data, int numThreads){
    vector<thread> threads;
    vector<size_t> partialCounts(numThreads,0);

    size_t chunkSize = data.size() / numThreads;

    for (int i = 0; i < numThreads; ++i) {
        size_t startIdx = i * chunkSize;
        size_t endIdx = (i == numThreads-1) ? data.size() : startIdx + chunkSize;
        threads.emplace_back(countEven, cref(data), startIdx, endIdx, ref(partialCounts[i]));
    }

    for (auto& t : threads) {
        t.join();
    }

    return accumulate(partialCounts.begin(), partialCounts.end(), size_t(0));

}

int main() {
    const size_t dataSize = 600'000'000; // 600 million
    const int numThreads = 6; // You can adjust this number based on your CPU // 6 Windows // 2 mac

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

// g++ -std=c++17 PS8.cpp -o PS8