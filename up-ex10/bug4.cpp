#include <iostream>
// there are 3 or 4 bugs here
double *sumByColumns(double *coeff, int w, int h) {
    double result[w];
    for (int i = 1; i <= w; i++) {
        result[i] = 0.0;
        for (j = 0; j < h; j++) {
            result[i] += coeff[i + j * w];
        }
    }
    return result;
}
int main(int argc, char **argv) {
    int w, h;
    std::cin >> w >> h;
    double *c = new double[w * h];
    for (int j = 0; j < h; j++) {
        for (int i = 0; i < w; i++) {
            std::cin >> c[i + w * j];
        }
    }
    double *sums = sumByColumns(c, w, h);
    for (int i = 0; i < w; i++) {
        std::cout << sums[i] << '\n';
    }
    delete[] sums;
    delete[] c;
}