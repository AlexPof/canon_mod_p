#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int get_degree(int* U,int max_size);

int main(int argc, char *argv[])
{
	int N,P,deg;
	int* U;
	int i,flag=0;
	unsigned long long int c;
	
	if(argc<3) {
		printf("Invalid number of arguments !\n");
		exit(1);
	}
	N = atoi(argv[1]);
	P = atoi(argv[2]);
	
	U = calloc(N+1,sizeof(int));
	
	if (U==NULL) {
		printf("Error during memory allocation...exiting now !\n");
		exit(1);
	}
	
	U[1]=1;
	c=0;
	
	while(flag==0) {
		deg=get_degree(U,N);
		c+=N-deg;
		for (i=N;i>-1;i--) {
			if (i>(N-deg-1))
				U[i]=U[i-(N-deg)];
			else
				U[i]=0;
		}
		U[0]=(U[0]+(P-1)*U[N])%P;
		U[1]=(U[1]+(P-1)*U[N])%P;
		U[N]=0;

		flag=(U[0]==1);
		for (i=1;i<N;i++)
			flag&=(!(U[i]>0));
	}
	printf("Canon size : %llu \n", c+1);
	free(U);
}

int get_degree(int* U,int max_size) {
	int i;
	
	for (i=max_size;i>-1;i--) {
		if (U[i]>0)
			return i;
	}
}