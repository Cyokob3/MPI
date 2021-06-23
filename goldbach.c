#include "mpi.h"
#include "stdio.h"
#include "stdlib.h"

int flag = 0;
double start, time, time2, time3;


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
    int i, a;
    int n = 3;
    char flag;
    start = MPI_Wtime();
    while(1){
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
        if (flag == 1) printf("ok");
        else {
            printf("error");
            break;
        }
        printf("\n");
        n++;
        if(n == 5001) break;
    }
    time=MPI_Wtime()-start;
    printf("used time = %f seconds.\n" ,time);
}

