
/*
ex. 5 a)
has_unique_digits
Checks if all digit in a number are encountered once.

param number - input number

return - true if all digits are encountered once
         false otherwise.
*/

bool has_unique_digits(int number)
{
    while (number > 0)
    {
        int current_digit = number % 10;
        int rest_number = number / 10;
        while (rest_number > 0)
        {
            if (rest_number % 10 == current_digit)
                return false;
            rest_number /= 10;
        }
        number /= 10;
    }
    return true;
}

/*
ex. 5 b)
has_fixed_digit_enqounters
Checks all digits in a number are encountere fixed number of times.

param number - input number
param encounters - number of fixed times a digit can be encountered

return - true if all digits are encountered the right amount of times
         false otherwise
*/

bool has_fixed_digit_encounters(int number, int encounters)
{
    while (number > 0)
    {
        int current_digit = number % 10;
        int current_digit_cnt = 0;
        int rest_number = 0;

        while (number > 0)
        {
            if (number % 10 == current_digit)
            {
                current_digit_cnt++;
            }
            else
            {
                rest_number *= 10;
                rest_number += number % 10;            
            }

            number /= 10;

        }
        if (current_digit_cnt != encounters)
            return false;
        number = rest_number;
    }
    return true;
}