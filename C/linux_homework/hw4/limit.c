
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>


int main(int arc , char *argv[])
{
    struct rusage r_usage;
	struct rlimit r_limit;
	int row, col , i , j , k ;
	int **A , **B , **C;

	col = atoi(argv[1]);
	row = atoi(argv[2]);

	A = (int **)malloc(sizeof(int *)*row);
	B = (int **)malloc(sizeof(int *)*row);
	C = (int **)malloc(sizeof(int *)*row);
	for(i=0 ; i<row ; i++){
		A[i] = (int *)malloc(sizeof(int )*col);
		B[i] = (int *)malloc(sizeof(int )*col);
		C[i] = (int *)malloc(sizeof(int )*col);
	}
			
// limit it
	getrlimit(RLIMIT_CPU, &r_limit);
	r_limit.rlim_max = 1;
	setrlimit(RLIMIT_CPU, &r_limit);

	for(i = 0 ; i < row ; i++)
			for(j = 0 ; j < col ; j++){
				A[i][j] = 1;
				B[i][j] = 2;
				C[i][j] = 0;
			}

	for(i = 0 ; i < row ; i++)
		for(k = 0 ; k < row ; k++)
			for(j = 0 ; j < col ; j++)
				C[i][k] += A[i][j] * B[j][i];

	for(i = 0 ; i < row ; i++){
			for(j = 0 ; j < col ; j++){
				printf("%d ", C[i][j]);
			}
			printf ("\n");
	}


    getrusage(RUSAGE_SELF, &r_usage);
    printf("CPU usage: User = %ld.%06ld, System = %ld.%06ld\n",
        r_usage.ru_utime.tv_sec, r_usage.ru_utime.tv_usec,
        r_usage.ru_stime.tv_sec, r_usage.ru_stime.tv_usec);


	free(A);
	free(B);
	free(C);
    exit(0);
}

