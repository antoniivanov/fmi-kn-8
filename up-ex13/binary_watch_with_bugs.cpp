#include <cstdio>
#include <iostream>

void add_new_result(char results[][6], int &results_index, int hour, int minute) {
    sprintf(results[results_index], "%d:%02d", hour, minute);
    results_index++;  // add new result
}

void get_all_combinations(char results[][6], int &results_index,
                          int hour, int minute,
                          int bits_list[], int num_start, int bits_list_size, int n) {
    if (n == 0) {
        add_new_result(results, results_index, hour, minute);
        return;
    }

    for (int i = num_start; i < bits_list_size; ++i) {
        if (bits_list[i] != -1) {  // -1 means already used
            int copy = bits_list[i];
            bits_list[i] = -1;
            if (i < 5) {
                hour += copy;
            }
            get_all_combinations(results,
                                 results_index, hour, minute,
                                 bits_list, i, bits_list_size, n - 1);
            if (i < 5) {
                hour -= copy;
            }
        }
    }
}

void read_all_combinations_for_n_bits(char results[1024000][6], int *result_size, int number_bits_set) {
    int results_size = 0;  // set initial size
    int bits_list[10] = {1, 2, 4, 8, 1, 2, 4, 8, 16, 32};
    get_all_combinations(results, results_size, 0, 0, bits_list, 0, 10, number_bits_set);
}

void print_results(char results[1024000][6], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << results[i] << ", ";
    }
    std::cout << std::endl;
}


int main() {
    int num;
    std::cin >> num;

    char results[1024000][6];
    int results_size;
    read_all_combinations_for_n_bits(results, &results_size, num);
    print_results(results, results_size);
    return 0;
}