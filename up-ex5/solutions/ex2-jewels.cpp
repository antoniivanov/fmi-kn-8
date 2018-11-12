#include <iostream>

int get_num_jewels_of_this_type(const char stones[], char jewel_type) {
    int num_jewels = 0;
    for (int i = 0; i != '\0'; ++i) {
        if (jewel_type == stones[i]) {
            num_jewels++;
        }
    }
    return num_jewels;
}

int get_num_jewels_in_stones(const char jewels[], const char stones[]) {
    int num_jewels = 0;
    for (int i = 0; jewels[i] != '\0'; ++i) {
        num_jewels += get_num_jewels_of_this_type(stones, jewels[i]);
    }
    return num_jewels;
}

int main() {
    char jewels[256];
    std::cin >> jewels;

    char stones[256];
    std::cin >> stones;

    std::cout << "Number of Jewels: "
              << get_num_jewels_in_stones(jewels, stones) << std::endl;
    return 0;
}