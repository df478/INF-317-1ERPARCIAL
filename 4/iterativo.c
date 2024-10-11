//Fórmula de Srinivāsa Rāmānujan demostrada en 1985 por Jonathan y Peter Borwein, descubierta en 1910. Es muy eficaz porque aporta 8 decimales a cada iteración

#include <stdio.h>
#include <math.h>

void ramanujan_pi_iterative(int terms, double *result) {
    double sum = 0.0;
    double factor = 2 * sqrt(2) / 9801;
    
    for (int k = 0; k < terms; k++) {
        double numerator = tgamma(4 * k + 1) * (1103 + 26390 * k);
        double denominator = pow(tgamma(k + 1), 4) * pow(396, 4 * k);
        sum += numerator / denominator;
    }
    
    *result = 1 / (factor * sum);
}

int main() {
    int terms = 10; // Número de términos
    double pi;
    ramanujan_pi_iterative(terms, &pi);
    printf("Valor de pi (iterativo): %.15f\n", pi);
    return 0;
}
