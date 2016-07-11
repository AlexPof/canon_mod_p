#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char *argv[])
{
	int N;
	int* U;
	int* V;
	int i,flag=0;
	unsigned long long L,entry=0,mult=0;
	char* output_filename;
	FILE* output_file=NULL;
	
	if(argc<2) {
		printf("Invalid number of arguments !\n");
		exit(1);
	}
	N = atoi(argv[1]);
	if(argc==3) {
		output_file=fopen(argv[2],"w");
		if (output_file==NULL) {
			printf("Error creating the output file...\n");
			exit(1);
		}
	}
	
	printf("Calculating for canon with motive {0,1,%d} mod 2\n**************\n",N);
	if (output_file!=NULL)
		fprintf(output_file,"Calculating for canon with motive {0,1,%d} mod 2\n**************\n",N);

	
	U = calloc(N,sizeof(int));
	V = calloc(N,sizeof(int));
	if (U==NULL || V==NULL) {
		printf("Error during memory allocation...exiting now !\n");
		exit(1);
	}
	for (i=0; i<N; i++) {
		U[i]=1;
		V[i]=1;
	}
		
	flag=0;
	
	clock_t tic = clock();
	
	while(flag==0) {

		for (i=0;i<N;i++) {
			if (U[i]==1) {
				entry = mult+((unsigned  long long)i);
				if (output_file!=NULL)
					fprintf(output_file,"%llu\n",entry);
				
				U[i]=1-U[i];
				if (i<N-1)
					U[i+1]=1-U[i+1];
				else
					V[0]=1-V[0];
				V[i]=1-V[i];
			}
		}
		
		flag=1;
		for (i=0; i<N; i++) {
			U[i]=V[i];
			if (i>0 && (V[i]-V[i-1])<0 && flag==1) {
				flag=0;
			}
		}
		for (i=0; i<N; i++)
			V[i]=1;
		mult+=N;
	}
	clock_t toc = clock();
	printf("Elapsed: %.8e seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
	L=entry+((unsigned  long long)N)+1;
	printf("*****************\nFinal length of canon with motive {0,1,%d} mod 2 : %llu \n",N,L);
	if (output_file!=NULL) {
		fprintf(output_file,"*****************\nFinal length of canon with motive {0,1,%d} mod 2 : %llu \n",N,L);
		fclose(output_file);
	}
	free(U);
	free(V);
}
