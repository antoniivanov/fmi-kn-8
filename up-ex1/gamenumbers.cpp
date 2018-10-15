#include<iostream>
using namespace std;

int main()
{
    unsigned int number;
    cin>>number;

    int sum = number%10;
    int k = number/10;
    do
    {
        sum += k%10;
        k = k/10;
    }
    while(k != 0);

    cout<<sum;
    cout<<endl;

    do
    {
        cout<<number%10;
        number=number/10;
    }
    while(number);

    /*int numToSum, numToReverse;
    cin >> numToSum;
    numToReverse = numToSum;

    // A)
    int digitSum = 0;
    while (numToSum > 0)
    {
        digitSum += (numToSum % 10);
        numToSum /= 10;
    }
    cout << "A) Sum of digits is " << digitSum << "\n";

    // B)
    int revercedNum = 0;
    while (numToReverse > 0)
    {
        revercedNum *= 10;
        revercedNum += (numToReverse % 10);
        numToReverse /= 10;
    }
    cout << "B) Reversed number is " << revercedNum << "\n";
    */


    return 0;

}
