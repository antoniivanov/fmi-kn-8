#include <iostream>
#include <algorithm>

int find_first_even_on_odd_index(const int array[], int array_size, int start) {
    for (int odd_index = start; odd_index < array_size; odd_index += 2) {
        if (array[odd_index] % 2 == 0) {
            return odd_index;
        }
    }
    return -1;
}

void sort_array_by_parity(int array[], int array_size) {
    int last_odd_index = 1;
    for (int even_index = 0; even_index < array_size; even_index += 2) {
        if (array[even_index] % 2 == 1) {
            int odd_index = find_first_even_on_odd_index(array, array_size, last_odd_index);
            std::swap(array[even_index], array[odd_index]);
             // keeping track of last_odd_index as optimization not to scan the full array every time
            last_odd_index = odd_index;
        }
    }
}