#include <iostream>

// include common string functions that we will reuse accross all exercises
#include "string_utilities.hpp"


int main()
{
    std::cout << "Please enter a string 1: ";
    char left_string[256];
    std::cin.getline(left_string, sizeof(left_string));

    std::cout << "Please enter a string 2: ";
    char right_string[256];
    std::cin.getline(right_string, sizeof(right_string));

    std::cout << "Comparison is " << compare_strings(left_string, right_string);
    std::cout << std::endl;
}