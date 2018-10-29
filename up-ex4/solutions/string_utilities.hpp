#pragma once

/**
	Returns the number of symbols in the string. 
*/
int get_string_length(const char str[])
{
    int index = 0;
    while (str[index] != '\0')
    {
        ++index;
    }
    return index;
}

/**
 * Returns if a character can be considered word separator. 
 */
bool is_word_separator(char c)
{
    return c == ' ' || c == '\t';
}

/**
 * Checks whether c is a decimal digit character.
 * Decimal digits are any of: 0 1 2 3 4 5 6 7 8 9 
*/
bool is_numerical_character(char c)
{
    return c >= '0' && c <= '9';
}


/**
 * Returns true if this is end of string symbol otherwise it is false.
 */
bool is_string_end(char string_symbol)
{
    return string_symbol == '\0';
}

/*
    Parses the C-string str interpreting its content as an integral number, which is returned as a value of type int.
*/
int string_to_int(const char string_number[])
{
    int result_number = 0;
    int char_index = 0;

    // get sign first
    int sign = +1;
    if (string_number[0] == '-') {
        sign = -1;
        char_index = 1;
    }

    // determine base of number
    int base = 10; 
    if (string_number[char_index] == '0' && string_number[char_index + 1] == 'x') {
        base = 16;
        char_index = char_index + 2;
    } else if (string_number[char_index] == '0' ) {
        base = 8;
        char_index = char_index + 1;
    }
    // convert number
    for (; string_number[char_index] != '\0'; ++char_index)
    {
        char c = string_number[char_index];

        if (is_numerical_character(c)) {
            result_number = result_number * base + (c - '0');
        }
        else { // invalid character or end of number - break
            break;
        }
    }
    return sign * result_number;
}


/**
 * This function starts comparing the first character of each string. 
 * If they are equal to each other, it continues with the following pairs 
 * until the characters differ or until a terminating null-character is reached.
 * Returns -1 if left is smaller, 0 if they are equal and 1 if left is bigger.
 */
int compare_strings(const char left_string[], const char right_string[])
{
    int index = 0;
    while (true)
    {
        if (is_string_end(left_string[index]) && is_string_end(right_string[index]))
        {
            return 0;
        }
        if (is_string_end(left_string[index]))
        {
            return -1;
        }
        if (is_string_end(right_string[index]))
        {
            return +1;
        }
        if (left_string[index] < right_string[index])
        {
            return -1;
        }
        if (left_string[index] > right_string[index])
        {
            return +1;
        }
        ++index;
    }
}


/**
 * Returns the index within this string of the first occurrence of the specified character,
 * starting the search at the specified index (by default 0)
 */
int find_first_index_of(const char input[], const char substring[], int start_pos = 0)
{
    int substring_index = 0;
    int index = start_pos;
    for (; !is_string_end(input[index]) && !is_string_end(substring[substring_index]); ++index) {
        if (input[index] == substring[substring_index]) {
            ++substring_index;
        }
        else {
            substring_index = 0;
        }
    }
    return is_string_end(substring[substring_index]) ? (index - substring_index) : -1;
}