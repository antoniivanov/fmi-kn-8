#include <cassert>
#include <iostream>

const int MAX_SIZE = 16;
const int MAX_SENTENCE = MAX_SIZE * MAX_SIZE;

void read_words_from_stdin(char word_matrix[][MAX_SIZE][MAX_SIZE], int *rows) {
    std::cin >> *rows;

    assert(*rows < MAX_SIZE);
    for (int i = 0; i < *rows; ++i) {
        int num_words;
        std::cin >> num_words;
        assert(num_words < MAX_SIZE);
        for (int j = 0; j < num_words; ++j) {
            std::cin >> word_matrix[i][j];
        }
        // our rows may have variable size so:
        // we will set it so that end of row is when we encounter the first empty string
        // e.g strlen(s) == 0 - means we are at end of row
    }
}

void read_words_from_fixed(char word_matrix[][MAX_SIZE][MAX_SIZE], int *rows) {
    *rows = 3;
    int cols = 2;
    assert(*rows < MAX_SIZE);
    for (int i = 0; i < *rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sprintf(word_matrix[i][j], "%d-%d", i, j);
        }
    }
}

void add_new_sentence(char sentences[][MAX_SENTENCE], int sentence_index, const char words[][MAX_SIZE], int num_words) {
    // clear any garbage - in other words delete any previous string
    sentences[sentence_index][0] = '\0';
    for (int i = 0; i < num_words; ++i) {
        if (i > 0) {
            strcat(sentences[sentence_index], " ");
        }
        strcat(sentences[sentence_index], words[i]);
    }
}

void copy(char words[][MAX_SIZE], const char source[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        strcpy(words[i], source[i]);
    }
}

void recursiveTraverse(int row, int col, int row_size,
                       const char word_matrix[][MAX_SIZE][MAX_SIZE],
                       char sentences[][MAX_SENTENCE], char words[][MAX_SIZE], int *sentence_index) {
    strcpy(words[row], word_matrix[row][col]);

    if (row == row_size - 1) {
        add_new_sentence(sentences, (*sentence_index)++, words, row_size);
    }
    for (int current_col = 0; strlen(word_matrix[row][current_col]) != 0; ++current_col) {
        recursiveTraverse(row + 1, current_col, row_size, word_matrix, sentences, words, sentence_index);
    }
}

void generate_sentences(const char word_matrix[][MAX_SIZE][MAX_SIZE], const int num_rows, char sentences[][MAX_SENTENCE]) {
    int sentence_index = 0;
    char words[MAX_SIZE][MAX_SIZE];
    for (int current_col = 0; strlen(word_matrix[0][current_col]) != 0; ++current_col) {
        recursiveTraverse(0, current_col, num_rows, word_matrix, sentences, words, &sentence_index);
    }
}

void print_sentences(const char sentences[][MAX_SENTENCE]) {
    for (int i = 0; strlen(sentences[i]) != 0; ++i) {
        std::cout << sentences[i] << std::endl;
    }
}

int main() {
    char word_matrix[MAX_SIZE][MAX_SIZE][MAX_SIZE] = {};  // make sure to initilize to zeros
    int num_rows;
    read_words_from_fixed(word_matrix, &num_rows);

    char sentences[MAX_SIZE * MAX_SIZE * MAX_SIZE][MAX_SENTENCE];
    generate_sentences(word_matrix, num_rows, sentences);

    print_sentences(sentences);

    return 0;
}