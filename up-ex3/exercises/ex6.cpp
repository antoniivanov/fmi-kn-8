

#include <iostream>
#include <ctime> 

/**
	Genreate random password and print it to the user to the standard output.

	param password_length - the number of symbols in the password
*/
void generate_password(int password_length) {

	srand(time(NULL));

	char first_allowed_char = '!'; // 33 
	char last_allowed_char = 'z'; // 125 
	int number_of_chars = last_allowed_char - first_allowed_char + 1; // +1 since both sides are included 
	for (int i = 0; i < password_length; ++i) {
		std::cout << static_cast<char>((rand() % number_of_chars) + first_allowed_char);
	}
	std::cout << std::endl;
}
 
int main() {
	const int min_password_length = 12;
	const int max_password_length = 32;
	int password_length = rand() % max_password_length + min_password_length;
	generate_password(password_length);
}