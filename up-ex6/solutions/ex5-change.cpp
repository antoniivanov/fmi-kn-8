#include <iostream>

/**
 * Prints the optimal sum of money 
 * for a given set of coins
 * 
 * input: money with floating point
 * return: none
*/

void printChange(float money)
{
    float change[4] = {1.0, 0.2, 0.05, 0.01};

    for (int i = 0; i < 4; i++)
    {
        int currentChangeCnt = 0;
        while(change[i] <= money)
        {
            money -= change[i];
            currentChangeCnt++;
        }
        std::cout << currentChangeCnt << '*';
        if (change[i] >= 1.0)
        {
            std::cout << change[i];
            std::cout << "lv. ";
        }
        else
        {
            std::cout << change[i]*100;
            std::cout << "st. ";
        }
    }
    std::cout << '\n';
}

int main() 
{
    float money;
    std::cin >> money;
    printChange(money);
    return 0;
}