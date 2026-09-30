#include<iostream>
using namespace std;


int main(){
    int n;
    double a[1000],tong = 0,tb = 0;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) tong += a[i];
    tb = tong / n;
    for(int i=0;i<n;i++){
        if(a[i] >= tb) cout<<a[i]<<" ";
    }
    return 0;
}