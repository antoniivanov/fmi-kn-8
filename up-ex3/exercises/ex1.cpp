
#include <iostream>

/**
	Print the following series sum:
	1 / 2 + 1 / 6 + 1 / 12 + 1 / 20 + .... + 1 / ((N - 1)*N)

	param num_elements - the number of elements in the series
	return - the sum of the series
*/
double series_sum(int num_elements)
{
	double sum = 0;
	for (int i = 1; i <= num_elements; ++i)
	{
		// std::cout << ((i + 1)*i) << std::endl;
		sum += 1.0 / static_cast<double>((i + 1) * i);
	}
	return sum;
}

int main()
{

	std::cout << "Please enter positive number." << std::endl;
	int num_elements;
	std::cin >> num_elements;
	if (num_elements <= 0)
	{
		std::cout << "Bad number. Please enter positive number." << std::endl;
		return 1;
	}
	std::cout << series_sum(num_elements) << std::endl;
	return 0;
}