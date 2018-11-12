#include <iostream>

/**
 * param numbers - the numbers sequence to search in 
 * param numbers_length - the length of the numbers array provided in the first parameter.
 * return the longest subsequnece of consescutive increasing numbers 
 */
int find_longest_increasing_subsequence_length(const int numbers[], const int numbers_length) {
    int max_length = 1;
    int current_length = 1;
    for (int i = 0; i < numbers_length - 1; ++i) { 
        /* ternary operator:
         * this is the same as 
         * if (numbers[i + 1]) { current_length++; } else { current_length = 1; }
         */
        current_length = numbers[i] < numbers[i + 1] ? current_length + 1 : 1;

        if (current_length > max_length) {
            max_length = current_length;
        }
    }
    if (current_length > max_length) {
        max_length = current_length;
    }
    return max_length;
}

/**
 * param numbers - the numbers sequence provided by user is stored here
 * return the number of elements read
 */
int read_numbers_sequence_from_stdin(int numbers[256], int max_length) {
    std::cout << "Please provide one by one numbers sequence (max 256) when finished click Crtl+Z (on windows) or Ctrl+DD :" << std::endl;
    int i = 0;
    while (!std::cin.eof() && i < max_length) {
        std::cin >> numbers[i++];
    }
    return i;
}

int main() {
    int numbers[256];
    int numbers_length = read_numbers_sequence_from_stdin(numbers, sizeof(numbers));
    int longest_subsequence_length = find_longest_increasing_subsequence_length(numbers, numbers_length);
    std::cout << "Longest increasing subsequence length is " << longest_subsequence_length << std::endl;
}