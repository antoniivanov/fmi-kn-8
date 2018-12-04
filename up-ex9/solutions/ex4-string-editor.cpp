#include <iostream>


/**
 * Counts the number ot characters in string recursively
 * 
 * param str
 * 
 * return length of string
 */
int stringLength(char* str)
{
	if (*str == '\0')
		return 0;
	return 1 + stringLength(str + 1);
}

/**
 * Takes to variables and swaps their original values 
 * 
 * param letter1
 * param letter2
 * 
 * return none
 */
void swap(char* letter1, char* letter2)
{
	char temp = *letter1;
	*letter1 = *letter2;
	*letter2 = temp;
}

/**
 * Takes begginig and ending of a string and swaps them,
 * continues recursively until the string is reversed. 
 * (until they reach the middle)
 * 
 * param begin
 * param end
 * 
 * return none
 */
void reverseString(char* begin, char* end)
{
	if (begin >= end)
		return;
	swap(begin, end);
	reverseString(begin + 1, end - 1);
}

/**
 * Takes a string and passes it to an overloaded function
 * reversing the given string.
 * 
 * param str
 * 
 * return none
 */
void reverseString(char* str)
{
	int length = stringLength(str);
	reverseString(str, str + length - 1);
}

int main()
{
    char a = 'f', b = 'j';
	std::cout << a << b << "\n";
	swap(&a, &b);
	std::cout << a << b << "\n";

	char str[] = "Hello World";
	std::cout << str << "\n";
	reverseString(str);
	std::cout << str << "\n";
    
    return 0;
}
