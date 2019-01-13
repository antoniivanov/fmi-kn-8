
#include <bitset>
#include <cstdio>
#include <iostream>

void add_new_result(char results[][6], int &results_index, int hour, int minute) {
    sprintf(results[results_index], "%d:%02d", hour, minute);
    results_index++;  // add new result
}

void read_binary_watch_variations(char results[1024000][6], int &results_size, int number_bits_set) {
    for (int h = 0; h < 12; ++h) {
        for (int m = 0; m < 60; ++m) {
            if (std::bitset<4>(h).count() + std::bitset<6>(m).count() == number_bits_set) {
                add_new_result(results, results_size, h, m);
            }
        }
    }
}

void print_results(char results[1024000][6], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << results[i] << ", ";
    }
    std::cout << std::endl;
}

int main() {
    int number_bits_set;
    std::cin >> number_bits_set;

    char results[1024000][6];
    int results_size;
    read_binary_watch_variations(results, results_size, number_bits_set);
    print_results(results, results_size);
    return 0;
}