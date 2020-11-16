#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_oct(int m, int n, const float *x, const char *name) {
    printf("%s = [ ", name);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++){
            printf(" %.4f", x[i * n + j]);
        }
        printf(" ;\n");
    }
    printf("];\n");
}

void fc(int m, int n, const float* x, const float* A, const float* b, float* y) {
    for (int k = 0; k < m; k++) {
        float sum = 0.0;
        sum += b[k];
        for (int i = 0; i < n; i++) {
            sum += (A[k * n + i] * x[i]);
        }
        y[k] = sum;
    }
}

int main() {
    float A[6] = {1, 2, 3, 4, 5, 6};
    float b[2] = {0.5, 0.25};
    float x[3] = {2, 3, 5};
    float o[2];
    fc(2, 3, x, A, b, o);
    print_oct(2, 3, A, "A");
    print_oct(2, 1, b, "b");
    print_oct(3, 1, x, "x");
    print_oct(2, 1, o, "o");
    return 0;
}
