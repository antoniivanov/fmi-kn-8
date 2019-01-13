double *smoothing(double *x, int size, int width) {
    double *result = new double[size];
    for (int i = 0; i < size; i++) {
        double s = 0;
        for (int j = 0; j < width; j++) s += x[(i + j) % size];
        result[i] = s / width;
    }
    return result;
}
double *iterativeSmoothing(double *x, int size, int width, int nb) {
    double *result;
    result = x;
    for (int k = 0; k < nb; k++) result = smoothing(result, size, width);
    return result;
}

int main(int argc, char **argv) {
    double a[] = {1, 2, 3, 4, 5, 6, 7};
    double *s = iterativeSmoothing(a, sizeof(a) / sizeof(double), 3, 1000000);
    delete[] s;
}