# Parallel Prime Number Counting with MPI

## Overview

This program demonstrates how to perform parallel prime number counting using MPI. The range of numbers is divided among multiple processes, with each process counting primes in its assigned segment. The master process gathers the counts from all processes and calculates the total number of primes.

## Differences in Code Implementation between 1 - 2 prime number counting 

The previous code is more manual and involves explicit array handling and communication, which can be more complex and error-prone. The current code leverages MPI’s collective communication functions (`MPI_Bcast` and `MPI_Reduce`), which simplifies the code and makes it more efficient and easier to understand.

## Compilation

To compile the program, use the following command:
```bash
mpicc -o prime_count_mpi prime_count_mpi.c
