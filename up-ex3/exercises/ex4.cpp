#include <iostream>

using namespace std;

/*
ex. 4 a)
Get the sum of the square of every odd number 
in the interval between begin and end.

param begin - brginning of interval
param end   - ending of interval

return - result of the sum of the squares
*/

int interval_square_sum(int begin, int end)
{
    int result = 0;
    while(begin >= end)
    {
        if (begin % 2 == 0)
            result += (begin*begin);
        begin++;
    }
    return result;
}

/*
ex. 4 b)
Find the number of ones encountered in a number in binary.

param number - input number (decimal)

return - the number of ones in the input number in 
*/

int num_of_ones_in_binary(int number)
{
    int cnt = 0;
    while (number > 0)
    {
        if (number % 2 == 1)
            cnt++;
        number /=10; 
    }
    return cnt;
}
