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
  int i, a;
  char flag;
  int n = 3;
  MPI_Status status;
  MPI_Init( &argc, &argv );
  MPI_Comm_rank( MPI_COMM_WORLD, &myrank );
  start = MPI_Wtime();
  printf("Hello from %d node\n",myrank);
  while(n <= 100){ 
    // 偶数であるかの判定を行う
    flag = 0;
    if(!(n % 2 == 0)){
      n++;
      continue;
    }
    printf("%d : ", n);
    for (i=2; i<n; i++){
      if(!(is_prime(i))) continue;
      a = n - i;
      if(!(is_prime(a))) continue;
      flag = 1;
    }
    if (flag == 1) printf("ok\n");
    else {
      printf("error\n");
      break;
    }
    n++;
  }
  time=MPI_Wtime()-start;
  printf("used time = %f seconds.\n" ,time);
  MPI_Finalize();
}

