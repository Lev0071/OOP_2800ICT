//main.c
int main() {
    const int rows = 3, cols = 4;

    // Initialize matrices A and B with example values
    vector<vector<int>> A(rows, vector<int>(cols, 1));  // all elements = 1
    vector<vector<int>> B(rows, vector<int>(cols, 2));  // all elements = 2
    vector<vector<int>> C(rows, vector<int>(cols));     // result matrix

    // Create a thread for each row
    vector<thread> threads;
    for (int i = 0; i < rows; ++i) {
        threads.emplace_back(addRow, cref(A), cref(B), ref(C), i);
    }

    // Join all threads
    for (auto& t : threads) {
        t.join();
    }

    cout << "Result matrix C = A + B:\n";
    for (const auto& row : C) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}
