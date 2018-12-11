#include <iostream>
#include "matrix-utilities.hpp"

void transpose(int matrix[128][128], const int size) {
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col <= row; ++col) {
            std::swap(matrix[row][col], matrix[col][row]);
        }
    }
}

void rotate_clockwise(int matrix[128][128], const int size) {
    int temp_matrix[128][128];
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            temp_matrix[row][col] = matrix[size - col - 1][row];
        }
    }
    copy_matrix(matrix, temp_matrix, size, size);
}

int main() {
    int size;
    int matrix[128][128];

    std::cin >> size;
    read_matrix_from_fixed(matrix, size, size);
    print_matrix(matrix, size, size);

    //transpose(matrix, size);
    print_matrix(matrix, size, size);

    rotate_clockwise(matrix, size);
    print_matrix(matrix, size, size);
    return 0;
}
