#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[])
{
	int N,P,mult;
	int* U;
	int i,mark=0,flag=0;
	unsigned long long L,entry=0;
	FILE* output_file=NULL;
	
	if(argc<3) {
		printf("Invalid number of arguments !\n");
		exit(1);
	}
	N = atoi(argv[1]);
	P = atoi(argv[2]);
	if(argc==4) {
		output_file=fopen(argv[3],"w");
		if (output_file==NULL) {
			printf("Error creating the output file...\n");
			exit(1);
		}
	}
	
	printf("Calculating for canon with motive {0,1,%d} mod %d\n**************\n",N,P);
	if (output_file!=NULL)
		fprintf(output_file,"Calculating for canon with motive {0,1,%d} mod %d\n**************\n",N,P);

	
	U = calloc(N+1,sizeof(int));
	if (U==NULL) {
		printf("Error during memory allocation...exiting now !\n");
		exit(1);
	}

	L=N+1;
	
	while(flag==0) {
		
		if (U[0]==0)
			mult=1;
		else
			mult=P-U[0]+1;
		
		L+=mark;
		entry+=mark;
		if (output_file!=NULL)
			fprintf(output_file,"(%llu,%d)\n",entry,mult);
					
		U[0]= (U[0]+mult) % P;
		U[1]= (U[1]+mult) % P;
		U[N]= (U[N]+mult) % P;

		flag=1;
		for (mark=0; mark<N+1; mark++) {
			if (U[mark]!=1) {
				flag=0;
				break;
			}
		}
		
		for (i=mark; i<N+1; i++)
			U[i-mark]=U[i];
		for (i=(N+1-mark); i<N+1; i++)
			U[i]=0;
	}

	printf("*****************\nFinal length of canon with motive {0,1,%d} mod %d : %llu \n",N,P,L);
	if (output_file!=NULL) {
		fprintf(output_file,"*****************\nFinal length of canon with motive {0,1,%d} mod %d : %llu \n",N,P,L);
		fclose(output_file);
	}
	free(U);
}
