

#include <iostream>

/**
	Print NxN matrix with 0 diagonal
	param matrix_size - the number of rows and columns of the matrix
*/
void print_matrix_with_zero_diagonal(int matrix_size)
{
	const int ZERO = 0;
	const char SPACE = ' ';
	for (int i = 1; i <= matrix_size; i++)
	{
		for (int k = i - 1; k >= 1; k--)
		{
			std::cout << k << SPACE;
		}
		std::cout << ZERO << SPACE;
		for (int j = 1; j <= matrix_size - i; j++)
		{
			std::cout << j << SPACE;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void print_matrix_with_zero_diagonal_solution2(int matrix_size)
{
	const int ZERO = 0;
	const char SPACE = ' ';
	for (int i = 1; i <= matrix_size; i++)
	{
		for (int j = 1; j <= matrix_size; j++)
		{
			std::cout << abs(i - j) << SPACE;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int main()
{

	std::cout << "Please enter the size of the NxN matrix" << std::endl;
	int matrix_size;
	std::cin >> matrix_size;
	if (matrix_size < 0)
	{
		std::cout << "Bad number. Please enter non-negative number." << std::endl;
		return 1;
	}
	print_matrix_with_zero_diagonal(matrix_size);
	return 0;
}