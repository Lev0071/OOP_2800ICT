#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <atomic>

using namespace std;

// Shared flag to indicate thread completion
atomic<bool> connected(false);

void connectToServer(int& duration_out) {
    cout << "[Thread] Connecting to server...\n";

    int delay = 7 + (rand() % 4); // 7–10 seconds
    auto start = chrono::steady_clock::now();

    this_thread::sleep_for(chrono::seconds(delay));

    auto end = chrono::steady_clock::now();
    duration_out = chrono::duration_cast<chrono::seconds>(end - start).count();

    cout << "[Thread] Connected successfully after " << duration_out << " seconds.\n";

    connected = true; // Signal completion
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "[Main] Starting program...\n";

    int threadDuration = 0;
    thread connectionThread(connectToServer, ref(threadDuration));

    int mainIterations = 0;
    auto mainStart = chrono::steady_clock::now();

    // Main thread continues working until connection completes
    while (!connected) {
        cout << "[Main] Working...\n";
        this_thread::sleep_for(chrono::milliseconds(400));
        mainIterations++;
    }

    connectionThread.join(); // Ensure thread cleanup
    auto mainEnd = chrono::steady_clock::now();
    auto mainDuration = chrono::duration_cast<chrono::seconds>(mainEnd - mainStart).count();

    cout << "\n=== Summary ===\n";
    cout << "Main thread worked for: " << mainDuration << " seconds (" << mainIterations << " cycles)\n";
    cout << "Connection thread took: " << threadDuration << " seconds\n";
    cout << "[Main] Done. Exiting program.\n";

    return 0;
}
