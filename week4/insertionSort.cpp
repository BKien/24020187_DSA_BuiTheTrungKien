#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    // j đại điện cho các phần tử đã được sắp xếp 
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Dời các phần tử lớn hơn key về phía sau một vị trí
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main(){
    int array[] = {3,4,1,2,5,0,9};
    insertionSort(array,7);
    for(int i=0;i<7;i++){
        cout<<array[i]<<" ";
    }

}