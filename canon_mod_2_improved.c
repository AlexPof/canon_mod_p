#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char *argv[])
{
	int N;
	int* U;
	int i,flag=0,c;
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
	if (U==NULL) {
		printf("Error during memory allocation...exiting now !\n");
		exit(1);
	}
	for (i=0; i<N; i++) {
		if ((i%2)==0) {
			U[i]=1;
			entry = mult+((unsigned  long long)i);
			if (output_file!=NULL)
				fprintf(output_file,"%llu\n",entry);
		}
	}
	mult+=N;
	flag=0;
	
	clock_t tic = clock();
	while(flag==0) {
		U[0]=U[0]^U[N-1];	/// Report the previous carry in the paving operation on the next line of entries
		
		flag=1;
		c=0;
		for (i=0;i<N;i++) {
			//////// 
			// Uncomment line (a) or (b) (but not both), these are equivalent: 
			// Line (a): adding 1+X+...+X^(N-1) first and then paving with 1+X
			// Line (b): paving with 1+X, then adding E0 = 1+X^2+X^4+....
			
			U[i]=U[i]^1; //(a)// 
			
			if (U[i]==1 && i<N-1) // This paves with 1+X
				U[i+1]=U[i+1]^1;
				
			// U[i]=U[i]^((i+1)%2); //(b)// 
			
			//// Collect entries and check for stopping
			if (U[i]==1) {
				if (c==1 && flag==1)
					flag=0;
				entry = mult+((unsigned  long long)i);
				if (output_file!=NULL)
					fprintf(output_file,"%llu\n",entry);
			} else
				c=1;
		}
		
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
}
