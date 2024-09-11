#include <mpi.h>
#include <stdio.h>
#include <math.h>
#include <time.h>


int i;

int is_prime(int num) {
    int i;
    for (i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char** argv) {
    int rank, size;
    int x, y, r, a, b, count = 0;
    double start, end;
    

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
   start = MPI_Wtime();
    if (rank == 0) {
        printf("Enter lower bound: ");
        scanf("%d", &x);
        printf("Enter upper bound: ");
        scanf("%d", &y);
       
    }

    MPI_Bcast(&x, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&y, 1, MPI_INT, 0, MPI_COMM_WORLD);

    r = (y - x) / size;

    a = x + rank * r;
        if (rank == size-1) {
    b = y;
} else {
    b = x + r - 1;
}

    int local_count = 0;
    for ( i = a; i <= b; i++) {
        local_count += is_prime(i);
    }

    MPI_Reduce(&local_count, &count, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
     end = MPI_Wtime();
    if (rank == 0) {
       
        printf("Total number of primes between %d and %d is %d\n", x, y, count+1);
        printf("Execution time: %f seconds\n", end - start);
    }

    MPI_Finalize();
    return 0;
}
