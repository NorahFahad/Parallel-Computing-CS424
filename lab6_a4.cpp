#include <stdio.h>
#include <iostream>
#include <string.h>
#include <mpi.h>

void Parallel_vector_sum(int& my_rank, int local_x[], /*in*/int local_y[]/*in*/, int local_z[]/*out*/, int local_n/*in*/); 

int main(void){
	int my_rank, n = 16;
	int comm_sz = 2;
	int local_n;
	int x[16] = { 0,0,1,1,2,2,3,3,0,0,1,1,2,2,3,3 };
	int local_x[2];
	int y[16] = { 0,0,1,1,2,2,3,3,0,0,1,1,2,2,3,3 };
	int local_y[2];
	int local_z[2];
	int z[16];
	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);

	local_n = n / comm_sz;
	MPI_Scatter(x, local_n, MPI_INT, local_x, local_n, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Scatter(y, local_n, MPI_INT, local_y, local_n, MPI_INT, 0, MPI_COMM_WORLD);
	Parallel_vector_sum(my_rank, local_x, local_y, local_z, local_n);
	MPI_Gather(&local_z, 2, MPI_INT, &z, 2, MPI_INT, 0, MPI_COMM_WORLD);

	if (my_rank == 0) {
		for (int i = 0; i < n; i++)
			printf("%d: %d\n", i, z[i]);
	}
	MPI_Finalize();
	return 0;
}

void Parallel_vector_sum(int& my_rank, int local_x[], /*in*/int local_y[]/*in*/, int local_z[]/*out*/, int local_n/*in*/) {
	int local_i;
	for (local_i = 0; local_i < local_n; local_i++)
		local_z[local_i] = local_x[local_i] + local_y[local_i];
}
