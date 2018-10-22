

#include <iostream>

/**
 * Checks if number is perfect - in other words the sum of its divisors is equal to the actual number
 * 
 * param number - the candidate number, it should be positive number 
 * return true if it's a perfect number, otherwise false
 */
bool is_perfect_number(int number)
{
	int divisor = 1;
	int divisor_sum = 0;
	while (divisor < number)
	{
		if (number % divisor == 0)
		{
			divisor_sum = divisor_sum + divisor;
		}
		divisor++;
	}
	return divisor_sum == number;
}

/** 
 * Get the sum of all perfect numbers saller than max_number 
 */
int sum_perfect_numbers(int max_number)
{
	int sum = 0;
	for (int candidate = 1; candidate <= max_number; ++candidate)
	{
		sum += is_perfect_number(candidate) ? candidate : 0;
	}
	return sum;
}

int main()
{

	std::cout << "Please enter upper bound of maximum perfect number." << std::endl;
	int max_number;
	std::cin >> max_number;
	if (max_number <= 0)
	{
		std::cout << "Bad number. Please enter positive number." << std::endl;
		return 1;
	}

	std::cout << sum_perfect_numbers(max_number);
	return 0;
}