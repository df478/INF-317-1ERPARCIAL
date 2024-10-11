#include <stdio.h>
#include <mpi.h>
#include <string.h>

#define MAX_STRING_LENGTH 100
#define VECTOR_SIZE 10

int main(int argc, char *argv[]) {
    int rank, size;
    char vector[VECTOR_SIZE][MAX_STRING_LENGTH];
    char recv_buffer[MAX_STRING_LENGTH];

    // Inicializar MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        // Procesador 0 inicializa el vector
        for (int i = 0; i < VECTOR_SIZE; i++) {
            snprintf(vector[i], MAX_STRING_LENGTH, "Elemento_%d", i);
        }
    }

    // Enviar el vector al resto de los procesos
    MPI_Bcast(vector, VECTOR_SIZE * MAX_STRING_LENGTH, MPI_CHAR, 0, MPI_COMM_WORLD);

    // Procesador 1 y 2 reciben y despliegan
    if (rank == 1) {
        printf("Procesador 1 (Posiciones Pares):\n");
        for (int i = 0; i < VECTOR_SIZE; i += 2) {
            printf("Posición %d: %s\n", i, vector[i]);
        }
    } else if (rank == 2) {
        printf("Procesador 2 (Posiciones Impares):\n");
        for (int i = 1; i < VECTOR_SIZE; i += 2) {
            printf("Posición %d: %s\n", i, vector[i]);
        }
    }

    // Finalizar MPI
    MPI_Finalize();
    return 0;
}

