

#include <iostream>
#include <cmath>

/**
	The function computes PI using Monte Carlo method.
	For details on the method see https://en.wikipedia.org/wiki/Monte_Carlo_method

	param n - the number of random tries
	return - the calculated PI value
*/
double compute_pi(const int num_attempts) {
	int darts_in_circle = 0;
	srand(time(0));

	for (int i = 0; i < num_attempts; ++i) {
		double x = rand() / (double)RAND_MAX;
		double y = rand() / (double)RAND_MAX;

		bool is_inside_circle = std::sqrt(x * x + y * y) < 1;
		if (is_inside_circle) {
			++darts_in_circle;
		}
	}

	// r^2 is 1 , and a/4 = darts_in_circle /n, yielding this for pi:
	return darts_in_circle / static_cast <double>(num_attempts) * 4;
}

#include <random>

/**
	The function computes PI using Monte Carlo method.
	For details on the method see https://en.wikipedia.org/wiki/Monte_Carlo_method
	It uses Uniform Random Distribution from the standard library.

	param n - the number of random tries
	return - the calculated PI value
*/
double compute_pi_using_distribution(const int num_attempts) {
	int darts_in_circle = 0;
	std::default_random_engine generator;
	std::uniform_real_distribution<double> distribution(0.0, 1.0);

	for (int i = 0; i < num_attempts; ++i) {
		double x = distribution(generator);
		double y = distribution(generator);
		
		bool is_inside_circle = std::sqrt(x * x + y * y) < 1;
		if (is_inside_circle) {
			++darts_in_circle;
		}
	}

	// r^2 is 1 , and a/4 = darts_in_circle /n, yielding this for pi:
	return darts_in_circle / static_cast <double>(num_attempts) * 4;
}


int main() {

	std::cout << compute_pi(5000000) << std::endl;
	std::cout << compute_pi_using_distribution(5000000);	
	return 0;
}