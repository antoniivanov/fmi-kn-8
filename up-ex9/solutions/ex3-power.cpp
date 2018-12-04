#include <iostream>

/** ex 4
 * Raises a number to the n-th power recursively
 * 
 * param base
 * param pow
 * 
 * return the power of base for given pow
 */
int power(int base, int pow)
{
	if (pow <= 1)
		return base;
	return base * power(base, pow - 1);
}

/**
 * Raises a number to the n-th power recursively, using
 * fast power alogrithm to reduce calculation time
 * 
 * param base
 * param power
 * 
 * return the power of base for given pow
 */
int fastPower(int base, int power)
{
	if (0 == power)
		return 1;
	if (1 == power)
		return base;
	if (0 == power % 2)
	{
		int result = fastPower(base, power / 2);
		return result * result;
	}
	int result = fastPower(base, power / 2);
	return result * result * base;
}

int main()
{
	std::cout << power(2, 5) << "\n";
	std::cout << fastPower(2,5)<< "\n";
    return 0;
}