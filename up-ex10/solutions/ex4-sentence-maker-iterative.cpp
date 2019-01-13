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
 

int get_sentences_length(const char row[][MAX_SENTENCE]) {
    int col = 0;
    for (col = 0; strlen(row[col]) != 0; ++col)
        ;
    return col;
}


int get_row_length(const char row[][MAX_SIZE]) {
    int col = 0;
    for (col = 0; strlen(row[col]) != 0; ++col)
        ;
    return col;
}


void generate_sentences_iterative(const char word_matrix[][MAX_SIZE][MAX_SIZE], 
                                  const int num_rows, char sentences[][MAX_SENTENCE]) {

    for (int col = 0; strlen(word_matrix[0][col]) != 0; ++col) {
        strcat(sentences[col], word_matrix[0][col]);
     }                             
    for (int row = 1; row < num_rows; ++row) {
        int num_sentences = get_sentences_length(sentences);
        int num_words = get_row_length(word_matrix[row]);
        // make new copies of existing sentences for each new columns
        for (int sentence_index = num_sentences - 1; sentence_index >= 0 ; --sentence_index)  {
            for (int col = 0; col < num_words; ++col) { 
                strcpy(sentences[num_words * sentence_index + col], sentences[sentence_index]);
            }
        }
        // append the new word to each sentence
        for (int col = 0; col < num_words; ++col) { 
            for (int sentence_index = 0; sentence_index < num_sentences; ++sentence_index)  {
                strcat(sentences[num_words * sentence_index + col], " ");
                strcat(sentences[num_words * sentence_index + col], word_matrix[row][col]);
            }
        }
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

    char sentences[MAX_SIZE * MAX_SIZE * MAX_SIZE][MAX_SENTENCE] = {};
    generate_sentences_iterative(word_matrix, num_rows, sentences);

    print_sentences(sentences);

    return 0;
}