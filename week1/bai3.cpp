#include <iostream>
using namespace std;

int main(){
    int n,result = 1;
    cin>>n;
    for(int i=1;i<=n;i++){
        result*=i;
    }
    cout<<result;
    //  độ phức tạp thời gian là n do sử dụng 1 vòng lặp
    // độ phức tạp không gian là 1 do số lượng các ô nhớ được sử dụng là hằng số
    return 0;
}


