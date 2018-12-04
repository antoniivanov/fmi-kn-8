#include <iostream>

/**
 * Takes two pointers to variables and swaps their original values 
 * 
 * param letter1
 * param letter2
 * 
 * return none
 */
void swap(int* number1, int* number2)
{
	int temp = *number1;
	*number1 = *number2;
	*number2 = temp;
}

/**
 * Prints an array of integers recursivelly 
 * 
 * param arr
 * param length
 * 
 * return none
 */
void printArray(int *arr, int length)
{
	if (0 == length)
	{
		std::cout << "\n";
		return;
	}
	std::cout << *arr << " ";
	printArray(arr + 1, length - 1);
}

/**
 * Goes through each permutation of a given array of
 * integers, and prints it at the end.
 * 
 * param arr
 * param length
 * 
 * return none
 */
void permutations(int* arr, int begin, int end)
{
	if (begin == end)
	{ 
		printArray(arr, end);
		return;
	}
	// Going through each of the remaining elements of the array
	// to swap them with the current one so we can continue recursively 
	// with all possible combinations, and then reverting the swap
	// to make sure the next iteration will have the same behaviour.
	for (int i = begin; i < end; i++)
	{
		swap(arr + begin, arr + i);
		permutations(arr, begin + 1, end);
		swap(arr + begin, arr + i); //backtrack 
	}
}

int main()
{
    int arr[4] = {1,2,3,4};
	permutations(arr, 0, 4);

	return 0;
}
