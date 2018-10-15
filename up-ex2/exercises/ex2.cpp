#include <iostream>

using namespace std;

int weekdayId(int day, int month)
{
	int monthsDays31 = 0;
	int tempMonth = month;


	if (month > 7)
	{
		monthsDays31 = 4;
		tempMonth -= 7;
	}

	if (tempMonth % 2 == 0)
		monthsDays31 += tempMonth / 2;
	else
		monthsDays31 += (tempMonth - 1) / 2;

	if (month > 2)
		monthsDays31 -= 2;

	int totalDays = ((30 * (month - 1)) + monthsDays31) + day;

	return (totalDays % 7);
	
}

void printWeekday(int dayId)
{
	switch (dayId)
	{
	case 1:
		cout << "Monday\n";
		break;
	case 2:
		cout << "Tuesday\n";
		break;
	case 3:
		cout << "Wednesday\n";
		break;
	case 4:
		cout << "Thursday\n";
		break;
	case 5:
		cout << "Friday\n";
		break;
	case 6:
		cout << "Saturday\n";
		break;
	case 0:
		cout << "Sunday\n";
		break;
	default:
		cout << "no such day\n";
	}
}

void* sth()
{
	int n = 9;
	return &n;
}
int main()
{
    int day, month;
	std::cout << "Enter day and month of 2018 \n";
	std::cin >> day >> month;
    printWeekday(weekdayId(day, month));
    return 0;
}