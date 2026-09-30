#include<iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    int a,b,ucln;
    cin>>a>>b;
    ucln = gcd(a,b);
    if(a%b==0) cout<<a/b;
    else if(b == 0) cout<<"error";
    else cout<<a/ucln<<"/"<<b/ucln;
    
    return 0;
}