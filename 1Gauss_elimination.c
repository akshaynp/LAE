/* created by Akshay on 09/11/2014*/
///To solve Linear algebraic Equation Ax=B using Gauss Elimination Method///

#include<stdio.h>
#include<time.h>
main()
{
    float A[20][20],X[20],B[20];
    int i,j,k,n,count=0,check=0;
    double s,p;
    clock_t start, end;
    float total_time=0.0;
    printf("Welcome in Gauss Elimination Method to solve equations of form A.X = B\n\n");
    printf("Enter the order of matrix\n");
    scanf("%d",&n);
//////////////////////Input coefficient of matrix and constant terms from User////////////////////////////
    printf("\nEnter the coefficient of matrix\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%f",&A[i][j]);
        }
    }
    printf("Enter the constant terms\n");
    for(i=0; i<n; i++)
    {
        scanf("%f",&A[i][n]);
    }
  ////////////////////Display Entered Matrix/////////////////////////
    printf("\n Entered Matrix is:\n\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n+1; j++)
        {
            printf(" %f\t ",A[i][j]);
        }
        printf("\n\n");
    }
    start = clock();
   ///////////////Reducing matrix into the row Echlon form///////////
    for(i = 0 ; i < n - 1 ; i++)
    {
        for(j = i + 1 ; j < n ; j++)
        {
            p = A[j][i] / A[i][i] ;
            for(k = i ; k < n + 1 ; k++)
            {
                A[j][k] = A[j][k] - p * A[i][k] ;   /// This instruction is executed 1/3 *n*n*n times
                count = count + 1;
            }
        }
    }
    /////////////////Augmented matrix will look like this/////////
    printf("\n Augmented Matrix is:\n\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n+1; j++)
        {
            printf(" %f\t ",A[i][j]);
        }
        printf("\n");
    }
    ///////////////////Back substitution method/////////////////////
    X[n-1] = A[n-1][n] / A[n-1][n-1] ;
    for(i = n - 2 ; i >= 0 ; i--)
    {
        s = 0 ;
        for(j = i + 1 ; j < n ; j++)
        {
            s = s + (A[i][j] * X[j]) ;
            X[i] = (A[i][n] - s) / A[i][i] ;
            check += 1;
        }
    }
    end = clock();
    total_time = ((double)(end-start))/(CLOCKS_PER_SEC/1000);
    printf("\nThe Solution of the given equations is :\n") ;
    for(i = 0 ; i < n ; i++)
    {
        printf("\nx[%d] = %.4f\n", i , X[i]);
    }
    printf("\n\nForward elimination instruction is executed == %d times",count);
    printf("\nBack substitution instruction is executed == %d times\n ",check);
    printf("Total time required to execute is = %f ms",total_time);
    getch() ;
}



