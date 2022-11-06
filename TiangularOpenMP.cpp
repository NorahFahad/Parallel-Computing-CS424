#include <iostream>
#include <stdio.h>
#include <omp.h>

void triangular(int n);

int main(int argc, char* argv[]) { //main function
    int n; //declare the number from user 

    printf("**Triangular number Series with openMP**\n");
    printf("The number of threads is (4)\n");

    printf("Enter number (n): ");
    scanf_s("%d", &n); //read the n from user

    while (true) { //while loop if the user enter non positive value
        if (n > 0)
            break; //break if the number is positive
        else {
            printf("Please enter positive number (n): ");
            scanf_s("%d", &n); //read the number again from user
        }//end else
    }//end while loop

    double start = omp_get_wtime(); //get the current time to calculate the start 

    triangular(n); //call triangular function (parallel part)

    double finish = omp_get_wtime(); //get the current time to calculate the finished time of the parallel part 

    printf("Elapsed time for the parallel part is: %f\n", (finish - start)," seconds"); //print the elapsed time for the parallel part

    return 0;
}//end main

void triangular(int n) { //the triangular function (parallel)
# pragma omp parallel for num_threads(12) schedule(static,1) //omp for loop with cyclic scheduling
    for (int i = 1; i <= n; i++) {
        printf("(Thread:%d) (Itration:%d) (Dots:%d)\n", omp_get_thread_num(), i, (i * (i + 1)) / 2);//the threads print its rank, itration its take and calculate the triangular dots
    }//end for loop 
}//end triangular function