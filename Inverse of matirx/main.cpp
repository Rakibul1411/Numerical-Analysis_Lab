#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;
#define N 3
#define epsilon 1e-10
double mat[N][2*N];
int main() {
    ifstream file("input.txt");
    if(!file){
        cout<<"Unable to open file";
        return 1;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 2*N; ++j) {
            file >> mat[i][j];
        }
    }
    file.close();

    for (int i = 0; i < N-1; ++i) {
        for (int j = i+1; j < N; ++j) {
            double temp = mat[j][i] / mat[i][i];
            for (int k = 0; k < 2*N; ++k) {
                mat[j][k] = mat[j][k] - temp*mat[i][k];
            }
        }
    }

    for (int i = N-1; i > 0; --i) {
        for (int j = i-1; j >= 0; --j) {
            double temp = mat[j][i] / mat[i][i];
            for (int k = 0; k < 2*N; ++k) {
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
        if (mat[i][i] != 0.0) {
            double t = mat[i][i];
            for (int j = 0; j < 2 * N; ++j) {
                mat[i][j] = mat[i][j] / t;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 2*N; ++j) {
            cout<<setw(7)<<setprecision(4)<<mat[i][j];
        }
        cout<<endl;
    }

    return 0;
}
