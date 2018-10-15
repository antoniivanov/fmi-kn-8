#include <iostream>

using namespace std;

char switchCase(char letter)
{
    if (letter >= 'A' && letter <= 'Z')
    {
        return letter + ('a' - 'A');
    }
    else if (letter >= 'a' && letter <= 'z')
    {
        return letter - ('a' - 'A');
    }
    return '\0';
}

int main()
{
    char letter;
    cin >> letter;
    cout << switchCase(letter) << "\n";

    return 0;
}