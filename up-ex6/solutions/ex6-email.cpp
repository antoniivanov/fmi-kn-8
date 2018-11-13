#include <iostream>

/**
 * Checks if a symbol is letter from the alphabet
 * input: symbol (char)
 * return: true is e letter
 *         false otherwise
*/
bool isLetter(const char symbol)
{
    return (symbol >= 'a' && symbol <= 'z') ||
           (symbol >= 'A' && symbol <= 'Z');
}

/**
 * Checks if a charachter is valid symbol of email address
 * input: symbol (char)
 * return: true is e valid
 *         false otherwise
*/
bool isValidPrefixSymbol(const char symbol)
{
    return  isLetter(symbol) || (symbol >= '0' && symbol <= '9') ||
           symbol == '-' || symbol == '_';
}

/**
 * Checks if an email has valid format
 * input: email address
 * return: true if it is valid
 *         false otherwise
*/
bool isValidEmail(const char email[])
{
    int index = 0;
    while(email[index] != '@')
    {
        if(email[index] == '\0')
            return false;
        if(!isValidPrefixSymbol(email[index]))
            return false;
        index++;
    }

    index++;
    
    while (email[index] != '.')
    {
        if(email[index] == '\0')
            return false;
        if(!isLetter(email[index]))
            return false;
        index++;
    }

    index++;

    while (email[index] != '\0')
    {
        if(!isLetter(email[index]))
            return false;
        index++;
    }
    
    return true;
}

int main()
{
    char email[255];
    std::cin.getline(email,255);
    if(isValidEmail(email))
    {
        std::cout << "True\n";
    }
    else
    {
        std::cout << "False\n";
    }

    return 0;
}