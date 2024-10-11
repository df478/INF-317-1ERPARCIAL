#include <stdio.h>

// Declaración de funciones
void suma(float* a, float* b, float* resultado);
void resta(float* a, float* b, float* resultado);
void multiplicacion(float* a, float* b, float* resultado);
void division(float* a, float* b, float* resultado);

int main() {
    float num1, num2;
    float resultado;

    // Solicitar al usuario que ingrese dos números
    printf("Ingrese el primer número: ");
    scanf("%f", &num1);
    printf("Ingrese el segundo número: ");
    scanf("%f", &num2);
    
    // Realizar las operaciones
    suma(&num1, &num2, &resultado);
    printf("Suma: %.2f\n", resultado);

    resta(&num1, &num2, &resultado);
    printf("Resta: %.2f\n", resultado);

    multiplicacion(&num1, &num2, &resultado);
    printf("Multiplicación: %.2f\n", resultado);
    
    // Verificar si se puede dividir
    if (num2 != 0) {
        division(&num1, &num2, &resultado);
        printf("División: %.2f\n", resultado);
    } else {
        printf("Error: División por cero.\n");
    }

    return 0;
}

// Definición de funciones
void suma(float* a, float* b, float* resultado) {
    *resultado = *a + *b;
}

void resta(float* a, float* b, float* resultado) {
    *resultado = *a - *b;
}

void multiplicacion(float* a, float* b, float* resultado) {
    *resultado = *a * *b;
}

void division(float* a, float* b, float* resultado) {
    *resultado = *a / *b;
}
