#include<stdio.h>
int main()
{
    printf("Enter the order of matrix: ");
    int n;
    scanf("%d",&n);
    double A[n][n],U[n][n],L[n][n],LI[n][n],qutiont;
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%lf",&A[i][j]);
            U[i][j]=A[i][j];
            if(i==j)
            {
                L[i][j]=1;
                LI[i][j]=1;
            }
            else
            {
                L[i][j]=0;
                LI[i][j]=0;
            }
        }
    }
    for(i=0;i<n;i++)
    {

        for(j=i+1;j<n;j++)
        {
            qutiont=U[j][i]/U[i][i];
            L[j][i]=qutiont;
            LI[j][i]=-1*qutiont;
            for(k=0;k<=n;k++)
            {
                U[j][k]=U[j][k]-qutiont*U[i][k];

            }
        }
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%lf\t",U[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

     for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%lf\t",L[i][j]);
        }
        printf("\n");
    }
    // double result[n][n];
    // for(i=0;i<n;i++)
    //  {
    //      for(j=0;j<n;j++)
    //      {
    //           result[i][j]=0;
    //           for(k=0;k<n;k++)
    //           {
    //              result[i][j]=result[i][j]+L[i][k]*U[k][j];
    //           }
    //      }
    //  }
    //  for(i=0;i<n;i++)
    //  {
    //     for(j=0;j<n;j++)
    //     {
    //        printf("%d\t",(int)result[i][j]);
    //     }
    //     printf("\n");
    //  }
    // printf("\n\n");
  double result[n][n];
    for(i=0;i<n;i++)
     {
         for(j=0;j<n;j++)
         {
              result[i][j]=0;
              for(k=0;k<n;k++)
              {
                 result[i][j]=result[i][j]+L[i][k]*LI[k][j];
              }
         }
     }
       for(i=0;i<n;i++)
     {
        for(j=0;j<n;j++)
        {
           printf("%lf\t",result[i][j]);
        }
        printf("\n");
     }
    printf("\n\n");

}