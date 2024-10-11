#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define N 4 // Tamaño de la matriz (N x N)

void print_matrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char** argv) {
    int rank, size;
    int A[N][N], B[N][N], C[N][N] = {0};

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Inicializar las matrices A y B solo en el proceso 0
    if (rank == 0) {
        // Inicializa la matriz A
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                A[i][j] = i + j; // Ejemplo simple
            }
        }

        // Inicializa la matriz B
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                B[i][j] = i - j; // Ejemplo simple
            }
        }
    }

    // Broadcast la matriz B a todos los procesos
    MPI_Bcast(B, N * N, MPI_INT, 0, MPI_COMM_WORLD);

    // Cada proceso calcula su parte de la matriz C
    for (int i = rank; i < N; i += size) {
        // Cada proceso calcula la fila i de la matriz C
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // El proceso 0 recibe los resultados de los otros procesos
    if (rank == 0) {
        // Copia la parte calculada por el proceso 0
        for (int i = 0; i < N; i++) {
            C[i][0] = C[i][0]; // Esta línea es redundante, solo para mostrar
        }
        // Recibe los resultados de los otros procesos
        for (int source = 1; source < size; source++) {
            for (int i = source; i < N; i += size) {
                MPI_Recv(&C[i], N, MPI_INT, source, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            }
        }
    } else {
        // Otros procesos envían sus resultados
        for (int i = rank; i < N; i += size) {
            MPI_Send(&C[i], N, MPI_INT, 0, 0, MPI_COMM_WORLD);
        }
    }

    // Proceso 0 imprime el resultado
    if (rank == 0) {
        printf("Matriz A:\n");
        print_matrix(A);
        printf("Matriz B:\n");
        print_matrix(B);
        printf("Resultado C (A * B):\n");
        print_matrix(C);
    }

    MPI_Finalize();
    return 0;
}

