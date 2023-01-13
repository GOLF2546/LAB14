#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    double sum = 0,total=0;
    for (int i=0 ; i<N;i++){
        sum += A[i];
    }
    double mean = sum/N;
    for (int j=0 ;j<N;j++){
        total += pow(A[j]-mean,2);
    }
    B[0] = mean;
    double std = sqrt((1.0/N)*total);
    B[1] = std;
    double msum = 1;
    for (int k = 0; k < N ; k++){
        msum *= A[k];
    }
    double geo = pow(msum,(1.0/N));
    B[2] = geo;
    double hsum = 0;
    for(int l = 0;l<N;l++){
        hsum += 1/A[l];
    }
    double har = N/hsum;
    B[3] = har;
    double max = A[0];
    for(int M = 0;M<N;M++){
        if(A[M]>max){
            max = A[M];
        }
    }
    B[4] = max;
    double min = A[0];
    for(int O = 0 ;O<N;O++){
        if(A[O]<min){
            min = A[O];
        }
    }
    B[5]=min;
}
