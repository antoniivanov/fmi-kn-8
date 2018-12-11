#include <iostream>
#include "matrix-utilities.hpp"

void flip_and_invert_image(int matrix[128][128], const int size) {
    for (int row_index = 0; row_index < size; ++row_index) {
        int *row = matrix[row_index];
        for (int col = 0; col < (size + 1) / 2; ++col) {
            int tmp = row[col] ^ 1;
            row[col] = row[size - 1 - col] ^ 1;
            row[size - 1 - col] = tmp;
        }
    }
}

int main() {
    int size;
    int matrix[128][128];

    std::cin >> size;
    read_matrix_from_stdin(matrix, size, size);
    flip_and_invert_image(matrix, size);
    print_matrix(matrix, size, size);
    return 0;
}
