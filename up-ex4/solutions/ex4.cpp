#include <iostream>

// include common string functions that we will reuse accross all exercises
#include "string_utilities.hpp"

  

int main()
{

    std::cout << "Please enter a string: ";
    char input_string[256];
    std::cin.getline(input_string, sizeof(input_string));

    std::cout << "Please enter a searched substr string: ";
    char searched_sub_string[256];
    std::cin.getline(searched_sub_string, sizeof(searched_sub_string));

    // implementation of find_first_index_of is in string_utilities.hpp
    // we can access it here because we've included it above.
    std::cout << "Index of seached string is " << find_first_index_of(input_string, searched_sub_string);
    std::cout << std::endl;
}