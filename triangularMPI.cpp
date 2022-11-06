#include <stdio.h>
#include <iostream>
#include <string.h>
#include <mpi.h>

int main(void) {
	int my_rank, comm_sz;
	int n;

	MPI_Init(NULL, NULL); //Initialize MPI
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);

	if (my_rank == 0) { //process 0 print
		printf("**Triangular number Series with MPI**\n");
		printf("Enter number (n): ");
		fflush(stdout); //flush everything before reading n from user
		scanf_s("%d", &n); //prosees 0 read the number n from user
	}

	MPI_Bcast(&n,1,MPI_INT,0, MPI_COMM_WORLD); //broadcast the number n from process 0 to all processes in the communicator

	double local_start, local_finish, local_elapsed, elapsed; //declare variables to caculate time 

	MPI_Barrier(MPI_COMM_WORLD); //make sure all processes in the communicator is start 

	local_start = MPI_Wtime(); //each process calculate its local start time

	for (int i = my_rank; i < n; i+=4) {//i is jump 4 each time to each process
		printf("(Process:%d) (Itration:%d) (Dots:%d)\n", my_rank, i, i * (i + 1) / 2); //each process prints its rank, the iteration it takes and the number of dots
	}

	local_finish = MPI_Wtime(); //each process calculate its local finish time
	local_elapsed = local_finish - local_start; //each process calculate its elapesd time in the parallel part

	MPI_Reduce(&local_elapsed, &elapsed, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD); //this for finding the longest time process and send it to process 1

	fflush(stdout); //flush

	if (my_rank == 0) {
		printf("Elapsed time is: %f seconds\n", elapsed); //process 1 print the elapsed time
	}

	MPI_Finalize(); //Finalize MPI
	return 0;
}
