#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    cout<<"Enter the number of variables of a linear system: ";
    int n;
    cin>>n;
    float system[n][n+1];
    cout<<"Enter the coefficient matrix: "<<endl;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n+1;j++)
        {
            cin>>system[i][j];
        }
    }
    //i have to check if this matrix is diagonally dominant or not
    for(i=0;i<n;i++)
    {
        int sum=0;
        for(j=0;j<n;j++)
        {
            if(i!=j)
            {
                sum+=fabs(system[i][j]);
            }

        }
        if(fabs(system[i][i])<sum)
        {
            cout<<"Not Diagonally Dominant"<<endl;
            return 0;
        }
    }
    float previous_solution[n];
    float new_solution[n];
    for(i=0;i<n;i++)
    {
        previous_solution[i]=0.0;
        new_solution[i]=0.0;
    }
    int flag=0;
    int iteration=0;
    //cout<<"iteration"<<" "<<"x\t"<<"y\t"<<"z"<<endl;
    while(n)
    {
        iteration++;
        for(i=0;i<n;i++)
        {
            new_solution[i]=system[i][n];
            for(j=0;j<n;j++)
            {
                if(i!=j)
                {
                    new_solution[i]-=new_solution[j]*system[i][j];
                }
            }
            new_solution[i]=new_solution[i]/system[i][i];
        }
        // cout<<"   "<<iteration<<"    ";
        // for(i=0;i<n;i++)
        // {
        //     cout<<new_solution[i]<<"\t";
        // }
        // cout<<endl;
        for(i=0;i<n;i++)
        {
            if(fabs(previous_solution[i]-new_solution[i])>.000001)
            {
                flag=1;
            }
            else
            {
                flag=0;
            }
        }
        if(flag==0)
        {
            break;
        }
        else
        {
            for(i=0;i<n;i++)
            {
                previous_solution[i]=new_solution[i];
            }
        }
    }
    for(i=0;i<n;i++)
    {
        cout<<new_solution[i]<<endl;
    }
    cout<<iteration;
}