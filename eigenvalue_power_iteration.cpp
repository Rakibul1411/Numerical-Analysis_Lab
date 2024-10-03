#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the matrix size: ";
    cin>>n;
    double matrix[n][n];
    double initial_eigen_vector[n][1];
    double new_eigen_vector[n][1],lambda_new;
    double breaking_eigen_vector[n][1];
    cout<<"Enter the matrix:"<<endl;
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>matrix[i][j];
        }
    }
    cout<<"Enter the initial eigen vector which is not zero:"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>initial_eigen_vector[i][0];
    }
    while(1)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<1;j++)
            {
                new_eigen_vector[i][j]=0;
                for(k=0;k<n;k++)
                {
                    new_eigen_vector[i][j]+=matrix[i][k]*initial_eigen_vector[k][j];
                }
            }
        }
        double max=-5555;
        for(i=0;i<n;i++)
        {
            if(max<fabs(new_eigen_vector[i][0]))
            {
                max=fabs(new_eigen_vector[i][0]);
            }
        }
        for(i=0;i<n;i++)
        {
            new_eigen_vector[i][0]/=max;
        }
        // for(i=0;i<n;i++)
        // {
        //     eucledian_distance+=new_eigen_vector[i][0]*new_eigen_vector[i][0];
        // }
        // eucledian_distance=sqrt(eucledian_distance);
        // for(i=0;i<n;i++)
        // {
        //     new_eigen_vector[i][0]=new_eigen_vector[i][0]/eucledian_distance;
        //     cout<<new_eigen_vector[i][0]<<" ";
        // }
        //cout<<eucledian_distance<<endl;
        for(i=0;i<n;i++)
        {
            breaking_eigen_vector[i][0]=fabs(fabs(initial_eigen_vector[i][0])-fabs(new_eigen_vector[i][0]));
        }
        double maximum=-5555;
        for(i=0;i<n;i++)
        {
            if(maximum<breaking_eigen_vector[i][0])
            {
                maximum=breaking_eigen_vector[i][0];
            }
        }
        lambda_new=max;
        if(maximum<.0001)
        {
            break;
        }
        //eucledian_distance=0;
        for(i=0;i<n;i++)
        {
            initial_eigen_vector[i][0]=new_eigen_vector[i][0];
        }
    }
    //cout<<eucledian_distance<<endl;
    for(i=0;i<n;i++)
    {
        cout<<new_eigen_vector[i][0]<<" ";
    }
    cout<<endl;
    cout<<lambda_new<<endl;
}