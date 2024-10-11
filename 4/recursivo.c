#include <stdio.h>
#include <math.h>

double ramanujan_pi_recursive(int k) {
    if (k == 0) {
        return tgamma(1) * (1103 + 26390 * k) / (pow(tgamma(1), 4) * pow(396, 0));
    } else {
        double numerator = tgamma(4 * k + 1) * (1103 + 26390 * k);
        double denominator = pow(tgamma(k + 1), 4) * pow(396, 4 * k);
        return (numerator / denominator) + ramanujan_pi_recursive(k - 1);
    }
}

void calculate_pi(int terms, double *result) {
    double factor = 2 * sqrt(2) / 9801;
    *result = 1 / (factor * ramanujan_pi_recursive(terms - 1));
}

int main() {
    int terms = 10; // Número de términos
    double pi;
    calculate_pi(terms, &pi);
    printf("Valor de pi (recursivo): %.15f\n", pi);
    return 0;
}
