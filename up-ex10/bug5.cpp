#include <iostream>
using namespace std;

// there are 4 bugs here.
int main() {
    int size, a[40];
    cout << "Enter size: ";
    cin >> size;
    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }
    //insertion sort https://en.wikipedia.org/wiki/Insertion_sort
    for (int j = 1; j < size - 1; j++) {
        int key = a[j];
        int i = j - 1;

        while ((key < a[i]) && (i >= 0)); {
            a[i + 1] = a[i];
            i = i + 1;
        }
        a[i + 1] = key;
    }
    cout << "\nSorted list is as follows\n";
    for (int i = 0; i < size; i++) {
        cout << endl << a[i];
    }
}