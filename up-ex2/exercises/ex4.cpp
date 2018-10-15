#include <iostream>

using namespace std;

int fastPower(int num, int power)
{
    int result = 1;
    while (power > 0)
    {
        if (power % 2 == 0)
        {
            // Divide the power by 2
            power /= 2;
            // Multiply base to itself
            num *= num;
        }
        else
        {
            // Decrement the power by 1 and make it even
            power -= 1;
            // Take care of the extra value that we took out
            // We will store it directly in result
            result *= num;

            // Now power is even, so we can follow our previous procedure
            power /= 2;
            num *= num;
        }
    }

    return result;
}

int slowPower(int num, int power)
{
    int result = 1;
    while(power > 0)
    {
        result *= num;
        power--;
    }
    return result;
}

int main()
{
    int num, power;
    cin >> num >> power;
    cout << slowPower(num, power);
    return 0;
}