#include <stdio.h>
#include <omp.h>

void fibonacci(int n) {
    // Variables compartidas y privadas
    int fib[n]; // Array para almacenar los términos de Fibonacci
    int i;

    // Inicialización de los dos primeros términos
    fib[0] = 0;
    fib[1] = 1;

    // Usamos OpenMP para paralelizar el cálculo de Fibonacci
    #pragma omp parallel for private(i) shared(fib)
    for (i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Despliegue de la serie
    printf("Fibonacci series up to %d terms:\n", n);
    for (i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &n);

    fibonacci(n);

    return 0;
}

