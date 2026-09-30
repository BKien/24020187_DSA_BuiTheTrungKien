#include<iostream>
using namespace std;

void deleteK(int k,int &n,int a[]){
    for(int i=k-1;i<n-1;i++){
        a[i] = a[i+1];
    }
    n = n-1;
}
void insert(int y,int m,int& n,int a[]){
    for(int i=n;i>=y-1;i--){
        a[i] = a[i-1];
    }
    a[y-1] = m;
    n = n+1;
}
int main(){
    int n,a[1000];
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    insert(3,10,n,a);
    for(int i=0;i<n;i++) cout<<a[i];
    return 0;
}