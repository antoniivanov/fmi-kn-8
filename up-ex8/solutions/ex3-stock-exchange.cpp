#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int n;
    int max = 0;
    int biggest_loss = 0;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v; cin.ignore();
        if (v > max) {
            max = v;
        }
        if (v - max < biggest_loss) {
            biggest_loss = v - max;
        }
    }
    
    

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << biggest_loss << endl;
}