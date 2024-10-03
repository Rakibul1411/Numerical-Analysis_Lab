#include<iostream>
#include<iomanip>
#include<math.h>

#define SIZE 10

using namespace std;

int main()
{
    double a[SIZE][SIZE], x[SIZE],x_new[SIZE];
    double temp, lambda_new, lambda_old, error;
    int i,j,n, step=1;

    cout<< setprecision(3)<< fixed;

    cout<<"Enter Order of Matrix: ";
    cin>>n;

    cout<<"Enter Tolerable Error: ";
    cin>>error;

    cout<<"Enter Coefficient of Matrix: "<< endl;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cout<<"a["<< i<<"]"<< j<<"]= ";
            cin>>a[i][j];
        }
    }

    cout<<"Enter Initial Guess Vector: "<< endl;
    for(i=1;i<=n;i++)
    {
        cout<<"x["<< i<<"]= ";
        cin>>x[i];
    }

    lambda_old = 1;
    up:
    for(i=1;i<=n;i++)
    {
        temp = 0.0;
        for(j=1;j<=n;j++)
        {
            temp = temp + a[i][j]*x[j];
        }
        x_new[i] = temp;
    }

    for(i=1;i<=n;i++)
    {
        x[i] = x_new[i];
    }

    lambda_new = fabs(x[1]);

    for(i=2;i<=n;i++)
    {
        if(fabs(x[i])>lambda_new)
        {
            lambda_new = fabs(x[i]);
        }
    }

    /* Normalization */
    for(i=1;i<=n;i++)
    {
        x[i] = x[i]/lambda_new;
    }

    /* Display */
    cout<< endl<< endl<<"STEP-"<< step<< endl;
    cout<<"Eigen Value = "<< lambda_new<< endl;
    cout<<"Eigen Vector: "<< endl;
    cout<<"[";
    for(i=1;i<=n;i++)
    {
        cout<< x[i]<<"\t";
    }
    cout<<"\b\b\b]"; /* \b is for backspace */

    /* Checking Accuracy */
    if(fabs(lambda_new-lambda_old)>error)
    {
        lambda_old=lambda_new;
        step++;
        goto up;
    }

    return(0);
}
