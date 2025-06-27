//matrix_utils.ixx
export module matrix_utils;
#include <vector>
#include <variant>
using namespace std;

export using Vec2D = vector<std::vector<int>>;
export using Vec1D = vector<int>;
export using Matrix = variant<Vec2D, Vec1D>;

export enum class MatrixForm { To1D, To2D };

export void convertMatrix(Matrix& matrix, int rows, int cols, MatrixForm direction) {
    if (direction == MatrixForm::To1D) {
        Vec2D& src2D = get<Vec2D>(matrix);
        Vec1D flat(rows * cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                flat[i * cols + j] = src2D[i][j];
        matrix = move(flat);
    } else {
        Vec1D& src1D = get<Vec1D>(matrix);
        Vec2D grid(rows, vector<int>(cols));
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                grid[i][j] = src1D[i * cols + j];
        matrix = move(grid);
    }
}

// Usage (e.g., main.cpp)
// ======================

// import matrix_utils;
// #include <iostream>

// int main() {
//     Matrix mat = Vec2D{{1, 2, 3}, {4, 5, 6}};
//     convertMatrix(mat, 2, 3, MatrixForm::To1D);
//     for (int x : std::get<Vec1D>(mat)) std::cout << x << " ";
//     std::cout << "\n";

//     convertMatrix(mat, 2, 3, MatrixForm::To2D);
//     for (const auto& row : std::get<Vec2D>(mat)) {
//         for (int x : row) std::cout << x << " ";
//         std::cout << "\n";
//     }

//     return 0;
// }
