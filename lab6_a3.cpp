#include <iostream>
#include <stdio.h>
#include <mpi.h>
#include <string.h>

int main(void) {
    int comm_sz;
    int my_rank;
    int sum;
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    //MPI_Reduce(&my_rank, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    //MPI_Bcast(&sum, 1, MPI_INT, 0, MPI_COMM_WORLD);

    MPI_Allreduce(&my_rank, &sum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

    printf("Procsss %d,Sum rank of %d processes, is %d", my_rank, comm_sz, sum);
  
    MPI_Finalize();
    return 0;
}

