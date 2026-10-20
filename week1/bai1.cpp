#include <iostream>
using namespace std;
// dùng 1 vòng lặp --> độ phức tạp thời gian n ; độ phức tạp không gian là n do sử dụng n ô nhớ cho mảng 
int main(){
    int n,a[1000],tong = 0;
    cin>>n; 
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) tong += a[i];
    cout<<"tong la "<<tong;
    return 0;
}
