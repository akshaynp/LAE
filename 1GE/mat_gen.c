#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int i,j,n;
	float **A;
	FILE *output_ptr;
        output_ptr = fopen("in_random_matrix_500*500.txt","w");
	printf("Enter value of N:");
	scanf("%d",&n);
	fprintf(output_ptr,"%d\n\n",n);
	A = (float**)malloc(n*sizeof(float*));
        for(i = 0; i < n; i++)
	{
            A[i] = (float*)malloc(n*sizeof(float));
	}
/*Generating input matrix*/	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			A[i][j] = rand() % 31 + 10;;
		}
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			fprintf(output_ptr,"%.2f ",A[i][j]);
		}
		fprintf(output_ptr,"\n");
	}
	fprintf(output_ptr,"\n\n\n");
	
/*Right hand side vector*/
	for(i=0;i<n;i++)
	{
		j = rand() % 31+1;
		fprintf(output_ptr,"%d  ",j);
		
	}
}

