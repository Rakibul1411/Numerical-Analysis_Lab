#include<stdio.h>
#include<math.h>

#define SIZE 10

int main()
{
    printf("We will use gauss jordan elemination for matrix inverse\n");
		 int i,j,k,n;
		 printf("Enter order of matrix: ");
		 scanf("%d", &n);
         double arr[n][2*n],qutiont;
		 printf("Enter the Matrix:\n");
		 for(i=0;i<n;i++)
		 {
			  for(j=0;j<n;j++)
			  {
				   scanf("%lf", &arr[i][j]);
			  }
		 }
		 for(i=0;i<n;i++)
		 {
			  for(j=n;j<2*n;j++)
			  {
				   if(j-i==n)
				   {
				    	arr[i][j] = 1;
				   }
				   else
				   {
				    	arr[i][j] = 0;
				   }
			  }
		 }
		 for(i=0;i<n;i++)
		 {
			  for(j=0;j<n;j++)
			  {
				   if(i!=j)
				   {
					    qutiont = arr[j][i]/arr[i][i];
					    for(k=0;k<2*n;k++)
					    {
					     	arr[j][k] = arr[j][k] - qutiont*arr[i][k];
					    }
				   }
			  }
		 }
         for(i=0;i<n;i++)
         {
            for(j=0;j<n;j++)
            {
                printf("%.3lf  ",arr[i][j]);
            }
            printf("\n");
         }
          printf("\n");
		 for(i=0;i<n;i++)
		 {
            double temp=arr[i][i];
			  for(j=0;j<2*n;j++)
			  {
			   	arr[i][j] = arr[i][j]/temp;
			  }
		 }
         for(i=0;i<n;i++)
         {
            for(j=0;j<2*n;j++)
            {
                printf("%.3lf  ",arr[i][j]);
            }
            printf("\n");
         }
		 printf("\nInverse Matrix is:\n");
		 for(i=0;i<n;i++)
		 {
			  for(j=n;j<2*n;j++)
			  {
			   	printf("%0.3lf\t",arr[i][j]);
			  }
			  printf("\n");
		 }
		 return(0);
}
