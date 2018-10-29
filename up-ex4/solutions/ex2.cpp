#include <iostream>

// include common string functions that we will reuse accross all exercises
#include "string_utilities.hpp"
 
int main()
{
    std::cout << "Please enter number: ";
    char string_number[16];
    std::cin >> string_number;
    // implementation of string_to_int is in string_utilities.hpp
    // we can access it here because we've included it above.
    int int_number =  string_to_int(string_number);
    if (int_number != 0) {
        std::cout << int_number << " is valid." << std::endl;
    } else {
        std::cout << string_number  << "is not valid or zero" << std::endl;
    }
}