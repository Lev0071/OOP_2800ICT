EXPLANATION
For matrix multiplication, since [A(m×n)] × [B(n×p)] = C(m×p) iff n == n → true,
then instead of dividing the mandatory dimension (which is n) by the number of threads, I should divide the output rows dimension (which is m) by the number of threads to get the chunk size.
This way, each thread works on its chunk-size amount of rows in the output matrix C.
Each chunk is calculated independently and combined together naturally, since the rows don’t overlap.

We will try to adapt:
size_t chunkSize = m / numThreads;

for (int i = 0; i < numThreads; ++i) {
    size_t startRow = i * chunkSize;
    size_t endRow = (i == numThreads - 1) ? m : startRow + chunkSize;

    // Launch thread to do rows [startRow, endRow)
}

with:

    for (int i = 0; i < m; ++i) { // over rows of C (rows of A)
        for (int j = 0; j < p; ++j) { // over cols of C (cols of B)
            for (int k = 0; k < n; ++k) { // over shared dimension (A cols / B rows)
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
In single-threaded: i = 0 to m

In multi-threaded: each thread gets its own slice of rows
startRow = i * chunkSize
endRow   = ... (next boundary or m)

for (int i = startRow; i < endRow; ++i) {
  ...
}