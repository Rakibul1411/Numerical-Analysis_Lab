#include <iostream>
#include <fstream>
//int mat[max][max];
using namespace std;
int main() {
    ifstream file ("input.txt");
    //cout<<"Enter the value of raw: ";
    int n;
    file>> n;
    double mat[n][n+1];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <=n ; ++j) {
            file>>mat[i][j];
        }
    }
   file.close();

    for (int i = 0; i < n-1; ++i) {

        for (int j = i+1; j < n ; ++j) {

            double temp = mat[j][i]/mat[i][i];

            for (int k = 0; k <=n ; ++k) {

                mat[j][k] = mat[j][k] - temp*mat[i][k];

            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <=n ; ++j) {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    double solution[n];
    solution[n-1] = mat[n-1][n]/mat[n-1][n-1];

    for (int i = n-2; i >=0 ; --i) {
        solution[i] = mat[i][n];
        for (int j = i+1; j < n; ++j) {
            solution[i] -= mat[i][j]*solution[j];
        }
        solution[i] = solution[i]/mat[i][i];
    }

   cout<<"Solution is: ";
    for (int i = 0; i < n; ++i) {
        cout<<solution[i]<<" ";
    }
    return 0;
}
