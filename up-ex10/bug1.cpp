
#include <iostream>
using namespace std;

// print first k numbers
void bugA() {
    int k, n;
    cin >> k;
    while (n < k) {
        cout << n++ << "\n";
    }
}

// is equal to 4
void bugB() {
    int x;
    std::cin >> x;
    if (x = 4)
        cout << x << "\n";
    else
        cout << "x is not equal to 4";
}

// initialize to 5
void bugC() {
    int *a = new int[100];
    for (int i = 1; i <= 100; i++) {
        a[i] = 5;
    }
}

// print divisors of k less than 100
void bugD() {
    int a[100];
    int k, n = 0;
    for (int i = 0; i < 100; i++) {
        a[i] = i;
    }
    cin >> k;
    do {
        n += k;
        cout << a[n] << '\n';
    } while (n < 100);
}

int main(int argc, char **argv) {
    bugA();
    // bugB();
    // bugC();
}