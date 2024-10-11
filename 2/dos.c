#include <stdio.h>

// Declaración de funciones
float suma(float a, float b);
float resta(float a, float b);
float multiplicacion(float a, float b);
float division(float a, float b);

int main() {
    float num1, num2;
    
    // Solicitar al usuario que ingrese dos números
    printf("Ingrese el primer número: ");
    scanf("%f", &num1);
    printf("Ingrese el segundo número: ");
    scanf("%f", &num2);
    
    // Realizar las operaciones
    printf("Suma: %.2f\n", suma(num1, num2));
    printf("Resta: %.2f\n", resta(num1, num2));
    printf("Multiplicación: %.2f\n", multiplicacion(num1, num2));
    
    // Verificar si se puede dividir
    if (num2 != 0) {
        printf("División: %.2f\n", division(num1, num2));
    } else {
        printf("Error: División por cero.\n");
    }
    
    return 0;
}

// Definición de funciones
float suma(float a, float b) {
    return a + b;
}

float resta(float a, float b) {
    return a - b;
}

float multiplicacion(float a, float b) {
    return a * b;
}

float division(float a, float b) {
    return a / b;
}
