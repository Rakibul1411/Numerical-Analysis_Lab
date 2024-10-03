#include<stdio.h>
int main()
{
     int m,n;
     printf("enter the row and column of 1 matrix: ");
     scanf("%d %d",&m,&n);
     int p,q;
     printf("Enter the row and column of 2 matrix: ");
     scanf("%d %d",&p,&q);
     int first[m][n];
     int second[p][q];
     int i,j,k;
     printf("Enter the input of first matrix:\n");
     for(i=0;i<m;i++)
     {
         for(j=0;j<n;j++)
         {
            scanf("%d",&first[i][j]);
         }
     }
     printf("Enter the input of second matrix:\n");
     for(i=0;i<p;i++)
     {
         for(j=0;j<q;j++)
         {
            scanf("%d",&second[i][j]);
         }
     }
     int result[m][q];
     for(i=0;i<m;i++)
     {
         for(j=0;j<q;j++)
         {
              result[i][j]=0;
              for(k=0;k<n;k++)
              {
                 result[i][j]=result[i][j]+first[i][k]*second[k][j];
              }
         }
     }
     for(i=0;i<m;i++)
     {
        for(j=0;j<q;j++)
        {
           printf("%d ",result[i][j]);
        }
        printf("\n");
     }

}
