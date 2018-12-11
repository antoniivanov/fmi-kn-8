#include <iostream>
#include "matrix-utilities.hpp"

void add_matrix(const int left_matrix[][128], const int right_matrix[][128], int result_matrix[][128],
                int rows_length, int columns_length) {
    for (int row_index = 0; row_index < rows_length; ++row_index) {
        for (int col_index = 0; col_index < columns_length; ++col_index) {
            result_matrix[row_index][col_index] = left_matrix[row_index][col_index] + right_matrix[row_index][col_index];
        }
    }
}

void multiply_square_matrix(const int left_matrix[][128], const int right_matrix[][128], int result_matrix[][128],
                            int matrix_size) {
    for (int row_index = 0; row_index < matrix_size; ++row_index) {
        for (int col_index = 0; col_index < matrix_size; ++col_index) {
            int cell_value = 0;
            for (int inner = 0; inner < matrix_size; ++inner) {
                cell_value += left_matrix[row_index][inner] * right_matrix[inner][col_index];
            }
            result_matrix[row_index][col_index] = cell_value;
        }
    }
}

int main() {
    int matrix[128][128];
    int rows_length = 4;
    int columns_length = 4;
    read_matrix_from_fixed(matrix, rows_length, columns_length);
    int matrix2[128][128];
    read_matrix_from_fixed(matrix2, rows_length, columns_length);

    int result_added[128][128];
    add_matrix(matrix, matrix2, result_added, rows_length, columns_length);
    print_matrix(result_added, rows_length, columns_length);
    int result_multiplied[128][128];
    multiply_square_matrix(matrix, result_added, result_multiplied, rows_length);
    print_matrix(result_multiplied, rows_length, columns_length);
}