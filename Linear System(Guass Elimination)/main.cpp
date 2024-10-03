#include<stdio.h>
#define EPS 0.1e5
int main()
{
    printf("We will use gauss jordan elemination for solving liner system\n");

    printf("Enter the number of unknowns: ");
    int n;
    scanf("%d",&n);
    double arr[n][n+1];
    int i,j,k;
    double quotiont;
    printf("Enter the co-efficient of variable:\n ");
    for(i=0;i<n;i++)
    {
       for(j=0;j<n+1;j++)
       {
           scanf("%lf",&arr[i][j]);
       }

    }
    for(i=0;i<n;i++)
    {
//        if(fabs(arr[i][i])<EPs)
//           {
//
//           }
        for(j=i+1;j<n;j++)
        {
            quotiont=arr[j][i]/arr[i][i];
            for(k=0;k<=n;k++)
            {
                arr[j][k]=arr[j][k]-quotiont*arr[i][k];

            }
        }

    }
    for(i=0;i<n;i++)
    {
       for(j=0;j<n+1;j++)
       {
          printf("%.3lf ",arr[i][j]);
       }
       printf("\n");
    }
    double solution[n];
    solution[n-1]=arr[n-1][n]/arr[n-1][n-1];
    for(i=n-2;i>=0;i--)
    {
        solution[i]=arr[i][n];
        for(j=i+1;j<n;j++)
        {
            solution[i]=solution[i]-solution[j]*arr[i][j];
        }
        solution[i]=solution[i]/arr[i][i];
    }
    for(i=0;i<n;i++)
    {
       printf("%.3lf\n",solution[i]);

    }

return 0;

}
