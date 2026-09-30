#include<iostream>
using namespace std;
int tong(int n,int m,int a[][1000]){
    int tong =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            tong +=a[i][j];
        }
    }
    return tong;
}

void deleteLine(int line,int n,int m,int a[][1000]){
    int a1[1000][1000],a2[1000][1000];
    for(int i=0;i<line-1;i++){
        for(int j=0;j<m;i++){
            a1[i][j] = a[i][j];
        }
    }

    for(int i=line-1;i<n;i++){
        for(int j=0;j<m;i++){
            a1[i][j] = a[i+1][j];
        }
    }

}
int main(){
    int n,m,a[1000][1000];
    cin>>n>>m;
    return 0;
}