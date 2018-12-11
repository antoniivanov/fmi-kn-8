
#include "matrix-utilities.hpp"
#include <iostream>
using namespace std;

/**
 * 
 * Given N create:
    N . . 2 1 2 . . N
    . . . . . . . 
    2 2 2 2 1 2 2 2 2
    1 1 1 1 1 1 1 1 1
    2 2 2 2 1 2 2 2 2
    . . . . . . . .
    N . . 2 1 2 . . N

 * For N = 3 :
    3 2 1 2 3
    2 2 1 2 2
    1 1 1 1 1
    2 2 1 2 2
    3 2 1 2 3
*/
int create_magical_matrix(int N, int matrix[][128]) {
    const int matrix_size = 2 * N - 1;

    for (int row = 0; row < N; ++row) {
        int oposite_row = matrix_size - row - 1;
        for (int col = 0; col < N; ++col) {
            int oposite_col = matrix_size - col - 1;
            int cell_value = std::min(N - row, N - col);
            matrix[row][col] = cell_value;
            matrix[oposite_row][col] = cell_value;
            matrix[row][oposite_col] = cell_value;
            matrix[oposite_row][oposite_col] = cell_value;
        }
    }
    return matrix_size;
}

int create_magical_matrix_solution2(int N, int matrix[128][128]) {
    // The size of matrix
    const int matrix_size = 2 * N - 1;

    // Fixing the range
    int dec = matrix_size;

    int start = N;
    int inc = 0;
    while (start != 0) {
        for (int row = 0; row < matrix_size; row++) {
            for (int col = 0; col < matrix_size; col++) {
                if (row == inc || row == dec - 1 || col == dec - 1 || col == inc) {
                    matrix[row][col] = start;
                }
            }
        }
        start--;
        inc++;
        dec--;
    }
    return matrix_size;
}

int main() {
    int N;
    std::cin >> N;

    int matrix[128][128];

    int matrix_size = create_magical_matrix(N, matrix);
    print_matrix(matrix, matrix_size, matrix_size);
}