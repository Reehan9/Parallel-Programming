#include <mpi.h>
#include <stdio.h>

int main() {
    MPI_Init(NULL, NULL);

    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Ensure there are at least two processes
    if (world_size < 2) {
        fprintf(stderr, "World size must be greater than 1\n");
        MPI_Finalize();
        return 1;
    }

    int send_number = world_rank;
    int recv_number;

    // Determine the rank of the target process
    int target_rank = (world_rank + 1) % world_size;

    MPI_Sendrecv(&send_number, 1, MPI_INT, target_rank, 0, 
                 &recv_number, 1, MPI_INT, (world_rank + world_size - 1) % world_size, 0, 
                 MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    printf("Process %d sent %d and received %d\n", world_rank, send_number, recv_number);

    MPI_Finalize();
    return 0;
}

