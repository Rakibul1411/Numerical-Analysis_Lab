#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;
#define N 3
#define epsilon 1e-10
double mat[N][N+1];
int main() {
    ifstream file("input.txt");
     if(!file){
         cout<<"Unable to open file";
         return 1;
     }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= N; ++j) {
            file >> mat[i][j];
        }
    }
    file.close();

    for (int i = 0; i < N-1; ++i) {
        for (int j = i+1; j < N; ++j) {
            double temp = mat[j][i] / mat[i][i];
            for (int k = 0; k <= N; ++k) {
                mat[j][k] = mat[j][k] - temp*mat[i][k];
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (fabs(mat[i][j]) < epsilon) {
                mat[i][j] = 0.0;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <N; ++j) {
            cout<<setw(7)<<setprecision(4)<<mat[i][j];
        }
        cout<<endl;
    }

    double determinant = 1.0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= N; ++j) {
            if ( i ==j ){
                determinant *= mat[i][j];
            }
        }
    }
    cout<< "Determinant of the matrix is: "<< fixed << setprecision(3) << determinant;

    double soln_x[N];
    for(int i=N-1; i>=0; i--)
    {
        double s = 0;
        for(int j=i+1; j<N; j++)
            s += mat[i][j]*soln_x[j];
        soln_x[i]=(mat[i][N]-s)/mat[i][i];
    }

    cout<<"\nThe Solution is:\n";
    for(int i=0; i<N; i++)
        cout<<"x["<<i+1<<"]="<<setw(7)<<setprecision(3)<<soln_x[i]<<endl;


    return 0;
}
