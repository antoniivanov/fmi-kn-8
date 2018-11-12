#include <iostream>

void flip_matrix(int matrix[][128], int rows_length, int columns_length) {
    for (int row_index = 0; row_index < rows_length; ++row_index) {
        for (int col_index = 0; col_index < (columns_length + 1) / 2; ++col_index) {
            int tmp = matrix[row_index][col_index];
            matrix[row_index][col_index] = matrix[row_index][columns_length - col_index - 1];
            matrix[row_index][columns_length - col_index - 1] = tmp;
        }
    }
}

void print_matrix(const int matrix[][128], int rows_length, int columns_length) {
    for (int row_index = 0; row_index < rows_length; ++row_index) {
        for (int col_index = 0; col_index < columns_length; ++col_index) {
            std::cout << matrix[row_index][col_index];
        }
        std::cout << std::endl;
    }
}

void read_input_matrix(int matrix[][128], int rows_length, int columns_length) {
    for (int row_index = 0; row_index < rows_length; ++row_index) {
        for (int col_index = 0; columns_length; ++col_index) {
            std::cin >>matrix[row_index][col_index];
        }
    }
}

int main() {
    int matrix_rows_length;
    int matrix_columns_length;
    std::cin >> matrix_rows_length >> matrix_columns_length;

    int matrix[128][128];
    read_input_matrix(matrix, matrix_rows_length, matrix_columns_length);
    flip_matrix(matrix, matrix_rows_length, matrix_columns_length);
    print_matrix(matrix, matrix_rows_length, matrix_columns_length);
    
    return 0;
}