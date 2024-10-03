#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of x and f(x): ";
    cin>>n;
    double x[n],fx[n];
    double least_square_system[n][n-1];
    double transpose_least_square_system[n-1][n];
    double constant_matrix[n][1];
    cout<<"Enter the value of x and the value of f(x): "<<endl;
    int i,j,k;
    for(i=0;i<n;i++)
    {
        cin>>x[i]>>fx[i];
        constant_matrix[i][0]=fx[i];
    }
    cout<<"x   ";
    for(i=0;i<n;i++)
    {
        cout<<x[i]<<" ";
    }
    cout<<endl;
    cout<<"fx  ";
    for(i=0;i<n;i++)
    {
        cout<<fx[i]<<" ";
    }
    cout<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            least_square_system[i][j]=1;
            for(k=0;k<j;k++)
            {
                least_square_system[i][j]*=x[i];
            }
            // cout<<least_square_system[i][j]<<" ";
        }
        // cout<<endl;
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n;j++)
        {
            transpose_least_square_system[i][j]=least_square_system[j][i];
            // cout<<transpose_least_square_system[i][j]<<" ";
        }
        // cout<<endl;
    }
    double result[n-1][n-1];
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            result[i][j]=0;
            for(k=0;k<n;k++)
            {
                result[i][j]=result[i][j]+transpose_least_square_system[i][k]*least_square_system[k][j];
            }
            //   cout<<result[i][j]<<" ";
        }
        //  cout<<endl;
    }
    double constant_production[n-1][1];
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<1;j++)
        {
            constant_production[i][j]=0;
            for(k=0;k<n;k++)
            {
                constant_production[i][j]+=transpose_least_square_system[i][k]*constant_matrix[k][j];
            }
            // cout<<constant_production[i][j]<<" ";
        }
        // cout<<endl;
    }
    double quotiont;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n-1;j++)
        {
            quotiont=result[j][i]/result[i][i];
            constant_production[j][0]=constant_production[j][0]-quotiont*constant_production[i][0];
            for(k=0;k<n-1;k++)
            {
                result[j][k]=result[j][k]-quotiont*result[i][k];

            }
        }
    }
    cout<<endl;
    double solution[n-1];
    solution[n-2]=constant_production[n-2][0]/result[n-2][n-2];
    for(i=n-3;i>=0;i--)
    {
        solution[i]=constant_production[i][0];
        for(j=i+1;j<n-1;j++)
        {
            solution[i]=solution[i]-solution[j]*result[i][j];
        }
        solution[i]=solution[i]/result[i][i];
    }
    // for(i=0;i<n-1;i++)
    // {
    //   cout<<solution[i]<<endl;
    // }
    cout<<"f(x)= ";
    for(i=0;i<n-1;i++)
    {
        if(i==0) cout<<solution[i];
        else if(i==1) cout<<"+("<<solution[i]<<")*x";
        else cout<<"+("<<solution[i]<<")*x^"<<i;
    }
    cout<<endl;
}