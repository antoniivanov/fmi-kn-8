#include <iomanip>
#include <iostream>

void nameDiamond(const char name[]) {
    int length = strlen(name);
    for (int i = 0; i < length; ++i) {
        for (int char_index = 0; char_index <= i; ++char_index) {
            std::cout << name[char_index];
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < length; ++i) {
        for (int space_index = 0; space_index <= i; ++space_index) {
            std::cout << " ";
        }
        for (int char_index = i + 1; char_index < length; ++char_index) {
            std::cout << name[char_index];
        }
        // the 2 for loops can be replaced with:
        // std::cout << std::setw(length) << name + i;
        std::cout << std::endl;
    }
}

void invert_image(int image[][128], int rows_length, int columns_length) {
    for (int row_index = 0; row_index < rows_length; ++row_index) {
        for (int col_index = 0; col_index < (columns_length + 1) / 2; ++col_index) {
            int tmp = image[row_index][col_index] ^ 1;
            image[row_index][col_index] = image[row_index][columns_length - col_index - 1] ^ 1;
            image[row_index][columns_length - col_index - 1] = tmp;
        }
    }
}

void print_image(const int image[][128], int rows_length, int columns_length) {
    for (int row_index = 0; row_index < rows_length; ++row_index) {
        for (int col_index = 0; col_index < columns_length; ++col_index) {
            std::cout << image[row_index][col_index];
        }
        std::cout << std::endl;
    }
}

int main() {
    //nameDiamond("CHRIS");
    // int image[3][128] = {{1, 0, 0}, {1, 1, 0}, {1, 1, 1}};
    // invert_image(image, 3, 3);
    // print_image(image, 3, 3);
}
// here t

