#include <iostream>
using namespace std;

int main(){
    int n,a[1000],tong = 0;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) tong += a[i];
    cout<<"tong la "<<tong;
    return 0;
}
