#include<iostream>
using namespace std;
// 2 vòng lặp --> độ phực tạp thời gian là n^2
// hàm phải sử dụng m*n ô nhớ --> độ phức tạp không gian là m*n
int tong(int n,int m,int a[][100]){
    int tong =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            tong +=a[i][j];
        }
    }
    return tong;
}

// 2 vòng lặp --> độ phức tạp thời gian là n^2
// hàm phải sử dụng m*n ô nhớ --> độ phức tạp không gian là m*n
void deleteLine(int line,int& n,int m,int a[][100]){
    for(int i=line-1;i<n;i++){
        for(int j=0;j<m;j++){
            a[i][j] = a[i+1][j];
        }
    }
    n = n - 1;
}
int main(){
    int n,m,a[100][100];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int sum = tong(n,m,a);
    cout<<sum;
    return 0;
}