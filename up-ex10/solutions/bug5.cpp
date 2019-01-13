#include <iostream>
using namespace std;

// there are 3 bugs here.
int main() {
    int size, a[40];
    cout << "Enter size: ";
    cin >> size;
    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }
    //insertion sort https://en.wikipedia.org/wiki/Insertion_sort
    for (int j = 1; j <= size - 1; j++) { // missing the last element 
        int key = a[j];
        int i = j - 1;

        while ((i >= 0) && (key < a[i])) { // check for index > 0 must be fore using it. Also semicolumn
            a[i + 1] = a[i];
            i = i - 1; // this is bug i = i - 1
        }
        a[i + 1] = key;
    }
    cout << "\nSorted list is as follows\n";
    for (int i = 0; i < size; i++) {
        cout << endl << a[i];
    }
}