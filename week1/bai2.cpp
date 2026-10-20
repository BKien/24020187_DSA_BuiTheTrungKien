#include<iostream>
using namespace std;
// sử dụng 2 vòng lặp --> độ phức tạp thời gian là n^2  ; độ phức tạp không gian là n do sử dụng n ô nhớ cho mảng
void sort(int n, int a[]){
    for(int i=0;i<n;i++){
        for(int j=i+1;j < n ;j++){
            if (a[i] > a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
int main(){
    int n,a[1000];
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(n,a);
    for(int i=0;i<n;i++)  cout<<a[i]<<" ";
}




