#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <mpi.h>



int main(int argc, char **argv)
{

  
  int num, rank, size;
  double pi_actual = 3.14159265359;
  double pi, mpi_pi;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
    //number of intervals
    num = 5;
    MPI_Bcast(&num, 1, MPI_INT, 0, MPI_COMM_WORLD);
    double seg = 1.0 / (double) num; // size of integration segments
    double sum = 0.0; // initialize sum (number of points that fall in quarter unit circle)
    for (int i = rank+1 ; i <= num; i += size){
        double x = seg* ((double) i - 0.5);
        sum += 4.0 / (1.0 + x*x);
    }
    mpi_pi = seg * sum;
    MPI_Reduce(&mpi_pi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    if (rank == 0){
      printf( "approximate pi is %.16f\n", pi);
      printf("percent error is %.16f\n", (fabs(pi - pi_actual)/pi_actual)*100.0);
    }
  MPI_Finalize();
  return 0;
  }
