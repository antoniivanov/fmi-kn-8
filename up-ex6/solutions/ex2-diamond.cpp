#include <iomanip>
#include <iostream>

void print_character_n_times(char character, int num_times) {
    for (int i = 0; i < num_times; ++i) {
        std::cout << character;
    }
}

void printDiamondTop(const char name[], int length) {
    for (int i = 0; i < length; ++i) {
        for (int char_index = 0; char_index <= i; ++char_index) {
            std::cout << name[char_index];
        }
        std::cout << std::endl;
    }
}

void printDiamondBottom(const char name[], int length) {
    for (int i = 0; i < length; ++i) {
        print_character_n_times(' ', i + 1);
        for (int char_index = i + 1; char_index < length; ++char_index) {
            std::cout << name[char_index];
        }
        // the above can be replaced with:
        // std::cout << std::setw(length) << name + i;
        std::cout << std::endl;
    }
}

void nameDiamond(const char name[]) {
    int length = strlen(name);
    printDiamondTop(name, length);
    printDiamondBottom(name, length);
}

int main() {
    char name[256];
    std::cin >> name;
    nameDiamond(name);
    return 0;
}