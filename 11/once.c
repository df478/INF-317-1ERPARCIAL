#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10 // Tamaño del vector

int main(int argc, char **argv) {
    int rank, size;
    int vec_a[N], vec_b[N], vec_result[N];
    int local_sum = 0;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        // Inicializar vectores en el maestro
        for (int i = 0; i < N; i++) {
            vec_a[i] = i + 1; // Ejemplo de inicialización
            vec_b[i] = (i + 1) * 2;
        }
    }

    // Broadcast de los vectores a todos los procesos
    MPI_Bcast(vec_a, N, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(vec_b, N, MPI_INT, 0, MPI_COMM_WORLD);

    // Cada procesador suma las posiciones que le corresponden
    for (int i = rank; i < N; i += size) {
        if (rank == 1 && i % 2 != 0) { // Proceso 1 suma posiciones impares
            local_sum += vec_a[i] + vec_b[i];
        } else if (rank == 2 && i % 2 == 0) { // Proceso 2 suma posiciones pares
            local_sum += vec_a[i] + vec_b[i];
        }
    }

    // Reunir resultados en el proceso maestro
    int total_sum = 0;
    MPI_Reduce(&local_sum, &total_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("La suma total de los vectores es: %d\n", total_sum);
    }

    MPI_Finalize();
    return 0;
}

