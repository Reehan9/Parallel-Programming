#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    int number;
    if (world_rank == 0) {
        // Process 0 sends a number to Process 1 and waits to receive from Process 1
        number = 0;
        MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Recv(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    } else if (world_rank == 1) {
        // Process 1 sends a number to Process 0 and waits to receive from Process 0
        number = 1;
        MPI_Send(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }

    MPI_Finalize();
    return 0;
}

