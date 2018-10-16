#include <iostream>

const int CHOICE_ROCK = 1;
const int CHOICE_PAPER = 2;
const int CHOICE_SCISSORS = 3;

int ask_player(int player_index) {
	int choice;
	do {
		std::cout << "Hello Player " << player_index << ". New Game is starting.";
		std::cout <<" Pick Rock/Paper/Scissors by entering the correct number: \n";
		std::cout << CHOICE_ROCK << ". Rock\n";
		std::cout << CHOICE_PAPER << ". Paper\n";
		std::cout << CHOICE_SCISSORS << ". Scissors\n";
		std::cin >> choice;
	} while (choice < 1 && choice > 3);
	
	// scroll down (print newlines) quickly to "hide" player's choice
	// that's basically the only portable way to clear screen
	for (int i = 0; i < 30; ++i) {
		std::cout << "\n";
	}
	return choice;
}

/// Accepts two arguments - both players choices(inputs)
/// Return 0,1,2 where:
/// 0 means a tie 
/// 1 means Player 1 wins
/// 2 means Player 2 wins
int decide_winner(int player_1_input, int player_2_input) {
	if (player_1_input == player_2_input) {
		return 0;
	}
	else {
		if (player_1_input == CHOICE_ROCK) {
			if (player_2_input == CHOICE_PAPER) {
				return 2;
			}
			else {
				return 1;
			}
		}
		if (player_1_input == CHOICE_PAPER) {
			if (player_2_input == CHOICE_ROCK) {
				return 1;
			}
			else {
				return 2;
			}
		}
		if (player_1_input == CHOICE_SCISSORS) {
			if (player_2_input == CHOICE_PAPER) {
				return 1;
			}
			else {
				return 2;
			}
		}
	}
}


void congratulate_winner(int winner) {
	if (winner > 0) {
		std::cout << "Player " << winner << " WINS!!!!. Congratulations!! \n\n";
	} else {
		std::cout << "It is a TIE !!!. No one wins this time. Give it another try ... ?\n\n";
	}
}

bool ask_if_player_want_to_continue() {
	int choice;
	do {
		std::cout << "Do you want to continue playing ? \n";
		std::cout << "1. YES\n";
		std::cout << "2. NO\n";
		std::cin >> choice;
	} while (choice != 1 && choice != 2);
	return choice == 1;
}

void run_rock_paper_scissors() {
	bool should_continue = true;
	while (should_continue) {
		int player_1_input = ask_player(1);
		int player_2_input = ask_player(2);
		int winner = decide_winner(player_1_input, player_2_input);
		congratulate_winner(winner);
		should_continue = ask_if_player_want_to_continue();
	}
}

int main() {
	run_rock_paper_scissors();
}