#include <iostream>


/**
 * Converts a letter to a lower case
 * Input: letter (char)
 * return: convertert letter in lower case
*/
char toLower(const char letter)
{
    return (letter >= 'A' && letter <= 'Z') ? letter + ('a'-'A') : letter;
}

/**
 * Checks if is a valid letter from tha alphabet
 * input: letter (char)
 * 
 * return true if is valid letter between a and z
 *        false if else 
*/
bool isLetter(const char letter)
{
    return (letter >= 'a' && letter <= 'z') ||
           (letter >= 'A' && letter <= 'Z'); 
}

/**
 * ex 4 a)
 * Prints the number of enqounters of each letter in a string
 * input: text
 * return: none 
*/
void printLetterEnqounters(const char str[])
{
    int unique[27] = { 0, };
    for (int i = 0; str[i] != '\0'; i++)
    {
        int currentCnt = 0;
        char currentLetter = toLower(str[i]);
        if(isLetter(str[i]) && unique[currentLetter - 'a'] == 0)
        {
            unique[currentLetter - 'a']++;
            for (int j = i; str[j] != '\0'; j++)
            {
                char toCompare = toLower(str[j]);
                if(currentLetter == toCompare)
                    currentCnt++;
            }
            std::cout << currentLetter << " -> " << currentCnt << '\n';
            currentCnt = 0;
        }
        
    }
    std::cout << '\n';
}

/**
 * ex 4 b)
 * prints the unique elements in array
 * input: text
 * return: none
*/
void printUnique(char str[])
{
    int unique[27] = { 0, };
    for (int i = 0; str[i] != '\0'; i++)
    {
        char tempLetter = toLower(str[i]);
        if(isLetter(str[i]) && unique[tempLetter - 'a'] == 0)
        {
            unique[tempLetter - 'a']++;
            std::cout << str[i];
        }
    }
    std::cout << '\n';
}

int main()
{
    char buffer[255];
    std::cin.getline(buffer,255);
    printLetterEnqounters(buffer);
    printUnique(buffer);
    return 0;
}