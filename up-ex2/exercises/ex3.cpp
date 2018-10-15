#include <iostream>

using namespace std;

int reverse(int num)
{
    int result = 0;
    while (num > 0)
    {
        result *= 10;
        result += num % 10;
        num /= 10; 
    }
    return result;
}

bool isPalindrome(int num)
{
    return num == reverse(num);
}

int main()
{
    int num;
    cin >> num;
    //cout << (isPalindrome(num) ? "True\n" : "False\n");
    if(isPalindrome(num))
    {
        cout << "True\n";
    }
    else
    {
        cout << "False\n";
    } 

    return 0;
}