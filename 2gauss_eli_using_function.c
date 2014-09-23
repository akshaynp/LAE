/* created by Akshay on 09/11/2014*/
///To solve Linear algebraic Equation Ax=B using Gauss Elimination Method///

#include<stdio.h>
#include<time.h>
float A[20][20],X[20],temp[20][20];
int n;

//void forward_Elimination(int n,double **A);
//void back_substitution(int n,double **A,double *X);
int forward_Elimination();
int back_substitution();

main()
{

    int i,j,k,count=0,check=0;
    double s;
    clock_t start, end;
    float total_time=0.0;
    printf("Welcome in Gauss Elimination_using function 2_ Method to solve equations of form A.X = B\n\n");
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
  count = forward_Elimination();

    /////////////////Augmented matrix will look like this/////////
    printf("\n Augmented Matrix is:\n\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n+1; j++)
        {
            printf(" %lf\t ",A[i][j]);
        }
        printf("\n");
    }

    ///////////////////Back substitution method/////////////////////
   check = back_substitution();

    ///////////////////////////////////////////////////////////////
    end = clock();

    total_time = ((double)(end-start))/(CLOCKS_PER_SEC/1000);
    printf("\nThe Solution of the given equations is :\n") ;
    for(i = 0 ; i < n ; i++)
    {
        printf("\nx[%d] = %f\n", i , X[i]) ;
    }
    printf("\n\nForward elimination instruction is executed == %d times\n",count);
    printf("\nBack substitution instruction is executed == %d times\n ",check);
    printf("Total time required to execute is = %f millisecond",total_time);
    //getch() ;
}
int forward_Elimination()
{
   // float temp[20][20];
    int l,out = 0;
    double p=0.0;
    int i,j,k,count=0;

/////////////Forward elimination Calculation and pivoting if necessary//////////////////////
    for(i=0;i<n;i++)
    {
        if(A[i][i]==0)
        {
            for(j=i+1;j<=n;j++)
            {
             //   out+=1;
                if(A[j][i]==0)
                {
                    out+=1;
                    printf("...\n");
                }
                else
                {
                    out+=1;
                    for(l=0;l<=n;l++)
                    {
                        temp[l][l]=A[out][l];
                        A[out][l]=A[i][l];
                        A[i][l]=temp[l][l];
                    }

                }
            }

        }

        else
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
    }
    return count;
}

int back_substitution()
{
    int i,j,check=0;
    double s;
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
    return check;
}
