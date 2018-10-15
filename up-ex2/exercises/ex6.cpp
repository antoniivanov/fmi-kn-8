#include <iostream>

using namespace std;

bool isPrime(int num)
{
    for(int div = 2; div < num; div++)
    {
        if(num % div == 0)
            return false;
    }
    return true;
}

void printPrimes(int num)
{
    for (int i = 2; i <= num; i++)
    {
        if(isPrime(i))
        {
            cout << i << " ";
        }
    }
    cout << "\n";
}

int main()
{
    int num;
    cin >> num;
    printPrimes(num);

    return 0;
}