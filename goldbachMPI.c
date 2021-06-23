#include "mpi.h"
#include "stdio.h"
#include "stdlib.h"

int main( argc, argv )
int argc;
char **argv;
{
  int myrank;
  double start, time;
  int n = 3;
  MPI_Status status;
  MPI_Init( &argc, &argv );
  MPI_Comm_rank( MPI_COMM_WORLD, &myrank );
  start = MPI_Wtime();
  printf("Hello from %d node\n",myrank);
  while(n <= 100){ 
    printf("%d : ", n);
    printf("ok\n"); 
    n++;
  }
  time=MPI_Wtime()-start;
  printf("used time = %f seconds.\n" ,time);
  MPI_Finalize();
}

