#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
 
int main() {
    int W;  // width of the building.
    int H;  // height of the building.
    cin >> W >> H;
    cin.ignore();
    int N;  // maximum number of turns before game over.
    cin >> N;
    cin.ignore();
    int X0;
    int Y0;
    cin >> X0 >> Y0;
    cin.ignore();

    int newX = X0;
    int newY = Y0;
    int maxX = W - 1;
    int maxY = H - 1;
    int minX = 0;
    int minY = 0;

    // game loop
    while (1) {
        string bombDir;  // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bombDir;
        cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        if (bombDir.find('U') != std::string::npos) {
            maxY = newY - 1;
        }
        if (bombDir.find('D') != std::string::npos) {
            minY = newY + 1;
        }
        if (bombDir.find('L') != std::string::npos) {
            maxX = newX - 1;
        }
        if (bombDir.find('R') != std::string::npos) {
            minX = newX + 1;
        }

        newX = minX + (maxX - minX) / 2;
        newY = minY + (maxY - minY) / 2;

        // the location of the next window Batman should jump to.
        cout << newX << " " << newY << endl;
    }
}