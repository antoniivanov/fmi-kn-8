#include <iostream>

// include common string functions that we will reuse accross all exercises
#include "string_utilities.hpp"

/**
 * Returns the number of words in a string.
 */
int get_word_count(const char str[])
{
    int word_count = 0;
    int string_length = get_string_length(str);

    bool encountered_word_characters = false;
    for (int char_index = 0; char_index < string_length; ++char_index)
    {

        if (is_word_separator(str[char_index]))
        {
            if (encountered_word_characters)
            {
                // no more word characters hence counting a new word
                ++word_count;
            }
            encountered_word_characters = false;
        }
        else
        {
            encountered_word_characters = true;
        }
    }
    if (encountered_word_characters)
    {
        // no more word characters hence counting a new word
        ++word_count;
    }
    return word_count;
}

void ex1_wordCount()
{
    std::cout << "Please enter a string: ";
    char input_string[256];
    std::cin.getline(input_string, sizeof(input_string));
    std::cout << "Entered string " << input_string;
    // implementation of get_string_length is in string_utilities.hpp (we will reuse it in other exercises)
    // we can access it here because we've included it above using #include "string_utilities.hpp"
    std::cout << ". Number of characters is " << get_string_length(input_string);
    std::cout << ". Number of words is " << get_word_count(input_string);
    std::cout << std::endl;
}
 
int main()
{ 
    ex1_wordCount();
}
