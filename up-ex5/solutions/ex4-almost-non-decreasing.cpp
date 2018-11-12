#include <iostream>

bool check_is_almost_non_decreasing(const int numbers[], const int num_elements) {
    int changed_element_index = -1;
    for (int i = 0; i < num_elements - 1; ++i) {
        if (numbers[i] > numbers[i + 1]) {
            if (changed_element_index >= 0) {
                return false;
            } else {
                changed_element_index = i;
            }
        }
    }

    return (  // no changed element found so it's non-decreasing - returning true
        changed_element_index == -1 ||
        // the single change required is to set numbers[0] = numbers[1];
        changed_element_index == 0 ||
        // set numbers[last-1] = numbers[last-2]
        changed_element_index == num_elements - 2 ||
        // set numbers[changed] = numbers[changed-1]
        numbers[changed_element_index - 1] <= numbers[changed_element_index + 1] ||
        // set numbers[changed+1] = numbers[changed]
        numbers[changed_element_index] <= numbers[changed_element_index + 2]);
}

int main() {
    int num_elements = 0;
    std::cin >> num_elements;
    int numbers[256];
    if (num_elements > sizeof(numbers)) {
        std::cout << "Number of elements must be less than " << sizeof(numbers);
        return 1;
    }
    for (int i = 0; i < num_elements; ++i) {
        std::cin >> numbers[i];
    }
    if (check_is_almost_non_decreasing(numbers, num_elements)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}