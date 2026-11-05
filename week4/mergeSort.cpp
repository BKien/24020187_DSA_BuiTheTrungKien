#include <iostream>
using namespace std;

// Hàm trộn hai mảng con đã sắp xếp
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];
    
    // sao chép vào 2 mảng tạm left và right
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    // Trộn hai mảng tạm vào mảng chính theo thứ tự tăng dần
    // đưa phần tử nhỏ hơn vào mảng 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Sao chép các phần tử còn sót lại (nếu có)
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }

    // Giải phóng bộ nhớ của hai mảng tạm
    delete[] L;
    delete[] R;
}

// Hàm chia đệ quy Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid =  (right + left) / 2; 

        mergeSort(arr, left, mid);     // Đệ quy nửa trái
        mergeSort(arr, mid + 1, right); // Đệ quy nửa phải

        merge(arr, left, mid, right);   // Gộp hai nửa lại
    }
}

int main() {
    int array[] = {3, 4, 1, 2, 5, 0, 9};
    int size = sizeof(array) / sizeof(array[0]);

    mergeSort(array, 0, size - 1);

    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
