// ゴールドバッチ
#include "mpi.h"
#include "stdio.h"
#include "stdlib.h"

int is_prime(n){
    int i;
    if(n < 2) return 0;
    for(i=2; i<n; i++){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}


int main( argc, argv )
int argc;
char **argv;
{
  int myrank;
  double start, time;
  int size;
  int rnode;/* right node */
  int lnode;/* left node */
  int sendmsg;/* Array for send */
  int recvmsg;/* Array for receive */
  int i, a;
  char flag;
  int n = 3;
  MPI_Status status;
  MPI_Init( &argc, &argv );
  MPI_Comm_rank( MPI_COMM_WORLD, &myrank );
  MPI_Comm_size( MPI_COMM_WORLD, &size );
  start = MPI_Wtime();
  if(myrank==0){
    printf("No. of process = %d.\n",size);
    printf("Time tick = %16.6E seconds.\n",MPI_Wtick());
    printf("_________________________________________\n");
  }
  rnode=(myrank+1)%size;
  lnode=(myrank-1+size)%size;
  printf("I am %d, right node=%d, left node=%d.\n",myrank, rnode,lnode);
  while(n <= 10){ 
    // 偶数であるかの判定を行う

    n++;
  }
  time=MPI_Wtime()-start;
  printf("I am %d used time = %f seconds.\n" ,myrank,time);
  MPI_Finalize();
}

