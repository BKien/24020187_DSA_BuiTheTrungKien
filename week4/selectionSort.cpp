#include <iostream>
using namespace std;

void selectionSort(int a[],int size){
    int min = 0;
    int index = 0;
    for(int i=0;i<size;i++){
        min = a[i];
        for(int j=i+1;j<size;j++){
            if(a[j] < min) {
                min = a[j];
                index = j;
            }
        }
        if (a[i] != min){
            int temp = a[i];
            a[i] = a[index];
            a[index] = temp;
        }
    }
}
int main(){
    int array[] = {3,4,1,2,5,0,9};
        selectionSort(array,7);
        for(int i=0;i<7;i++){
            cout<<array[i]<<" ";
        }
    return 0;
}
