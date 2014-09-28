/* created by Akshay on 09/24/2014*/

#include<stdlib.h>
#include<stdio.h>
#include<math.h>

void forward_Elimination(int n,float **A,float *X);
void back_substitution(int n,float **A,float *X);

int main()
{
        float **A,*X,**orig_mat,*res,*error;
        int i,j,k,n;
	printf("\n\n*Welcome in Gauss Elimination method using partial_pivoting  to solve equations of form A.X = B\n\n");
/////////////////////Input the Order of Matrix//////////////////////////////////////////////////////
    	printf("*Enter the order of matrix :\n");
    	scanf("%d",&n);
//////////////////////Memory Allocation for matrix and right hand side vector//////////////////////////
        A = (float**)malloc(n*sizeof(float*));
	orig_mat = (float**)malloc(n*sizeof(float*));
        for(i = 0; i < n; i++)
	{
            A[i] = (float*)malloc(n*sizeof(float));
	    orig_mat[i] = (float*)malloc(n*sizeof(float));
	}
        X = (float*)malloc(n*sizeof(float));
	res = (float*)malloc(n*sizeof(float));
	error = (float*)malloc(n*sizeof(float));
//////////////////////Input coefficient of matrix and constant terms from User//////////////////////////
 	printf("\n\n*Enter the coefficients of matrix :\n");
	for(i=0; i<n; i++)
    	{
        	for(j=0; j<n; j++)
       		{
            		scanf("%f",&A[i][j]);
			orig_mat[i][j] = A[i][j];
        	}
    	}
    	printf("\n\n*Enter the Right hand side vector :\n");
    	for(i=0; i<n; i++)
    	{
        	scanf("%f",&A[i][n]);
		orig_mat[i][n] = A[i][n];
    	}
/////////////////////////////////////Display Entered Matrix//////////////////////////////////////
    	printf("\n\n*Entered Matrix is :\n");
    	for(i=0; i<n; i++)
    	{
        	for(j=0; j<n+1; j++)
       	 	{
            		printf(" %.2f\t ",A[i][j]);
        	}
        	printf("\n\n");
    	}
////////////////////////////////////////generation of scalar matrix//////////////////////////////
        forward_Elimination(n,A,X);
/////////////////////////Augmented form of the matrix///////////////////////////////
	printf("\n\n*The Augmented form of the matrix is :\n");
        for(i=0;i<n;i++)
	{
            for(j=0;j<=n;j++)
            { 
		printf("%.2f\t",A[i][j]);
	    }
            printf("\n");
        }
/////////////////////////////////backward substitution Method///////////////////////////////
        back_substitution(n,A,X);
////////////////////////////////display the solution of Equations///////////////////////////////
        printf("\n\n*The solution of above equations are :\n\n");
        for(i=0;i<n;i++)
	{
        	printf("X[%d] = %.4f\n", i, X[i]);
	}
////////////////////////////////Error Identification///////////////////////////////////////////
	printf("\n*Using above solutions,the given linear algebraic equations evaluates to(Approximate):\n\n");
	for(i=0;i<n;i++)
	{
        	for(j=0;j<n;j++)
		{
			res[i] = res[i] + X[j]*orig_mat[i][j] ;
			printf("(%f)*(%f) + ",X[j],orig_mat[i][j]);
		}
		printf("= %lf",res[i]);
		printf("\n");
	}
	/*Display Error grnerated*/
	printf("\n*Error= ((Actual - Approximate)/Actual)*100\n\n");
	for(i=0;i<n;i++)
	{	
		//error[i] = ((res[i] - orig_mat[i][n])/res[i])*100;
		error[i] = ((orig_mat[i][n]-res[i])/(orig_mat[i][n]))*100;
		printf("%d.(%lf) - (%lf) = %-le\n",i+1,orig_mat[i][n],res[i], error[i]);
	}
////////////////////////////////free allocated memory////////////////////////////////////////
        for(i = 0; i < n; i++)
        {
		free(A[i]);
	}
        free(A);
        free(X);
    	return 0;
}

void forward_Elimination(int n,float **A,float *X)
{
	float app,mult;
	int i,j,k,p;
	for(i=0;i<n;i++)
	{
            app = A[i][i];
            p = i;
/*find largest no of the columns and row no. of largest no.*/
            for(k = i+1; k < n; k++)
            {
		if(fabs(app) < fabs(A[k][i]))
	   	{
               		app = A[k][i] ;
               		p = k;
            	}
	    }
/*swaping the elements of diagonal row and row containing largest no*/
            for(j = 0; j <= n; j++)
            {
                X[j] = A[p][j];
                A[p][j] = A[i][j];
                A[i][j] = X[j];
            }
/*calculating triangular matrix using Forward Elimination method*/
            for(j=i+1;j<n;j++)
	    {
                mult = A[j][i]/A[i][i];
                for(k=0;k<=n;k++)
		{		
                    A[j][k] = A[j][k] - mult * A[i][k];
        	}    
	    }
        } 
}

/*for calculating value of unknows using backward substitution method*/
void back_substitution(int n,float **A,float *X)
{
	int i,j;
	float sum;
        for(i=n-1;i>=0;i--)
        {
            sum = 0;
            for(j=i+1;j<n;j++)
            {
		sum = sum + A[i][j]*X[j];
	    }
            X[i] = (A[i][n]-sum)/A[i][i];
        }
}
