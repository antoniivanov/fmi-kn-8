#include <iostream>

typedef char word_matrix_type[30][30][20];

void read_matrix_from_fixed(word_matrix_type matrix, int *size) {
    *size = 4;
    for (int i = 0; i < *size; ++i) {
        for (int j = 0; j < *size; ++j) {
            sprintf(matrix[i][j], "%d%d", i, j);
        }
    }
}

void get_main_diagonal_sentence(char sentence[], const word_matrix_type matrix, const int size) {
    for (int i = 0; i < size; ++i) {
        strcat(sentence, matrix[i][i]);
    }
}

void get_minor_diagonal_sentence(char sentence[], const word_matrix_type matrix, const int size) {
    for (int i = 0; i < size; ++i) {
        strcat(sentence, matrix[i][size - i - 1]);
    }
}

void find_if_cross_sentences_are_the_same(const word_matrix_type matrix, const int size) {
    char main_sentence[900] = {};
    get_main_diagonal_sentence(main_sentence, matrix, size);
    char minor_sentence[900] = {};
    get_minor_diagonal_sentence(minor_sentence, matrix, size);

    std::cout << "main diagonal sentence: " << main_sentence << std::endl;
    std::cout << "minor diagonal sentence: " << minor_sentence << std::endl;
    if (strcmp(main_sentence, minor_sentence) == 0) {
        std::cout << "Both sentences are the same" << std::endl;
    } else {
        std::cout << "Both sentences are NOT the same" << std::endl;
    }
}

int main() {
    word_matrix_type matrix;
    int size;
    read_matrix_from_fixed(matrix, &size);
    find_if_cross_sentences_are_the_same(matrix, size);
}