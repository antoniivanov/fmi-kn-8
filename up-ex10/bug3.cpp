

int kindOfLog2(int n) {
    if (n < 0) {
        return 1;
    } else {
        return 1 + kindOfLog2(n / 2);
    }
}

void bugA() {
    int k = kindOfLog2(987);
}

#include <iostream>
void bugB() {
    double s;
    for (double x = 0; x != 1; x += 0.01) s += 1 / (1 + x);
    std::cout << s << std::endl;
}

int main(int argc, char** argv) {
    // bugA
    // bugB
}