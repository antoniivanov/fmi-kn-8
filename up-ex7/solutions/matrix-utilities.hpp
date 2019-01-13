#include <iostream>

void print_matrix(const int matrix[][128], int rows_length, int columns_length) {
    for (int row_index = 0; row_index < rows_length; ++row_index) {
        for (int col_index = 0; col_index < columns_length; ++col_index) {
            std::cout << matrix[row_index][col_index] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void read_matrix_from_fixed(int matrix[][128], int rows_length, int columns_length) {
    for (int row_index = 0; row_index < rows_length; ++row_index) {
        for (int col_index = 0; col_index < columns_length; ++col_index) {
            matrix[row_index][col_index] = row_index * rows_length + col_index;
        }
    }
}

void read_matrix_from_stdin(int matrix[][128], int rows_length, int columns_length) {
    for (int row_index = 0; row_index < rows_length; ++row_index) {
        for (int col_index = 0; col_index < columns_length; ++col_index) {
            std::cin >> matrix[row_index][col_index];
        }
    }
}

void copy_matrix(int destination_matrix[][128], const int source_matrix[][128], int rows_length, int columns_length) {
    for (int row_index = 0; row_index < rows_length; ++row_index) {
        for (int col_index = 0; col_index < columns_length; ++col_index) {
            destination_matrix[row_index][col_index] = source_matrix[row_index][col_index];
        }
    }
}
