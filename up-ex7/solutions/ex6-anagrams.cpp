#include <cstring>
#include <iostream>

bool is_anagram(const char first_word[], const char second_word[]) {
    int word_size = strlen(first_word);
    if (strlen(second_word) != word_size) {
        // we cannot have anagrams with different lengths
        return false;
    }

    int met_characters[128] = {0};  // initialize to 0
    const int met_characters_length = sizeof(met_characters) / sizeof(met_characters[0]);

    for (int i = 0; i < word_size; ++i) {
        met_characters[(int)first_word[i]]++;
        met_characters[(int)second_word[i]]--;
    }
    
    for (int i = 0; i < met_characters_length; ++i) {
        if (met_characters[i] != 0) {
            return false;
        }
    }

    return true;
}

bool is_anagram_with_sorting(const char first_word[], const char second_word[]) {
   int  word_size = strlen(first_word);
    if (strlen(second_word) != word_size) {
        // we cannot have anagrams with different lengths
        return false;
    }
    char first_word_copy[1000];
    char second_word_copy[1000];
    strncpy(first_word_copy, first_word, word_size);   
    strncpy(second_word_copy, second_word, word_size);
    std::sort(first_word_copy, first_word_copy + word_size);
    std::sort(second_word_copy, second_word_copy + word_size);
    return strncmp(first_word_copy, second_word_copy, word_size) == 0;
}

void print_anagrams(const char words[1000][1000], int num_words) {
    for (int i = 0; i < num_words; ++i) {
        for (int j = i + 1; j < num_words; ++j) {
            if (is_anagram(words[i], words[j])) {
                std::cout << "(" << words[i] << ", " << words[j] << ")\n";
            }
        }
    }
}

int main() {
    int num_words;
    std::cin >> num_words;

    char words[1000][1000];
    for (int i = 0; i < num_words; ++i) {
        std::cin >> words[i];
    }
    print_anagrams(words, num_words);
}