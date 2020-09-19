#include <iostream>
using namespace std;

void matmul(int *A,int *B,int *R,int n){
    if(n==1){
        (*R)+=(*A)*(*B);
    }
    else{
        matmul(A,B,R,n/4);
        matmul(A,B+(n/4),R+(n/4),n/4);
        matmul(A+2*(n/4),B,R+2*(n/4),n/4);
        matmul(A+2*(n/4),B+(n/4),R+3*(n/4),n/4);
        matmul(A+(n/4),B+2*(n/4),R,n/4);
        matmul(A+(n/4),B+3*(n/4),R+(n/4),n/4);
        matmul(A+3*(n/4),B+2*(n/4),R+2*(n/4),n/4);
        matmul(A+3*(n/4),B+3*(n/4),R+3*(n/4),n/4);
    }
}

int main()
{
    int n,x;
    cout<<"Enter the index size of the Matrix : ";
    cin>>n;
    int *A = new int[n*n];
    int *B = new int[n*n];
    int *R = new int[n*n];
    cout<<"Enter the elements of array A : \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>x;
            *(A + i*n + j) = x;
            *(R + i*n + j) = 0;
        }
    }
    cout<<"Enter the elements of array B : \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>x;
            *(B + i*n + j) = x;
        }
    }
    cout<<"Multiplied Matrix : \n";
    matmul(A,B,R,n*n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<< *( R+ i*n + j) <<" ";
        cout<<'\n';
    }
}
