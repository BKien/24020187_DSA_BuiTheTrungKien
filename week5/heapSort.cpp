#include "ArrayList.h"
#include <iostream>
using namespace std;

// ========================================================
// CẤU TRÚC DỮ LIỆU MAX HEAP
// Sử dụng các hàm của ArrayList từ file ArrayList.h bên ngoài
// ========================================================
class MaxHeap {
private:
    ArrayList list; // Danh sách mảng lưu trữ các nút của heap

    // Chỉ số node cha của node i
    int parent(int i) {
        return (i - 1) / 2;
    }

    // Chỉ số node con trái của node i
    int leftChild(int i) {
        return 2 * i + 1;
    }

    // Chỉ số node con phải của node i
    int rightChild(int i) {
        return 2 * i + 2;
    }

    // Hoán đổi 2 phần tử tại vị trí i và j bằng hàm get và set của ArrayList
    void swapElements(int i, int j) {
        int temp = list.get(i);
        list.set(i, list.get(j));
        list.set(j, temp);
    }

    // Vun lên (sift up): đẩy phần tử tại vị trí i lên đúng vị trí
    // Dùng khi thêm một phần tử mới vào cuối heap
    void siftUp(int i) {
        while (i > 0 && list.get(i) > list.get(parent(i))) {
            swapElements(i, parent(i));
            i = parent(i);
        }
    }

    // Vun xuống (sift down): đẩy phần tử tại vị trí i xuống đúng vị trí
    // Dùng khi lấy phần tử lớn nhất ra (extractMax) hoặc khi buildHeap
    void siftDown(int i) {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        // So sánh với con trái
        if (left < list.size() && list.get(left) > list.get(largest)) {
            largest = left;
        }

        // So sánh với con phải
        if (right < list.size() && list.get(right) > list.get(largest)) {
            largest = right;
        }

        // Nếu phần tử lớn nhất không phải là node cha hiện tại
        if (largest != i) {
            swapElements(i, largest);
            siftDown(largest); // Đệ quy vun tiếp xuống cây con
        }
    }

public:
    // Khởi tạo Max Heap rỗng
    MaxHeap() {}

    // Kiểm tra Heap có rỗng không
    bool empty() {
        return list.empty();
    }

    // Lấy số lượng phần tử hiện có trong Heap
    int size() {
        return list.size();
    }

    // Xem giá trị lớn nhất (ở đỉnh heap, tức phần tử đầu tiên của list) - O(1)
    int getMax() {
        if (empty()) {
            cout << "Heap dang rong!" << endl;
            return -1;
        }
        return list.get(0);
    }

    // Thêm một phần tử vào Max Heap - O(log n)
    void insert(int val) {
        list.push_back(val);
        siftUp(list.size() - 1);
    }

    // Lấy và xóa phần tử lớn nhất ra khỏi Max Heap - O(log n)
    int extractMax() {
        if (empty()) {
            cout << "Heap dang rong!" << endl;
            return -1;
        }

        int maxVal = list.get(0); // Lưu lại giá trị lớn nhất ở đỉnh

        // Nếu heap chỉ còn 1 phần tử
        if (list.size() == 1) {
            list.pop_back();
            return maxVal;
        }

        // Đưa phần tử cuối cùng lên vị trí gốc (index 0)
        int lastVal = list.get(list.size() - 1);
        list.set(0, lastVal);

        // Xóa phần tử cuối cùng khỏi danh sách mảng
        list.pop_back();

        // Vun phần tử mới ở gốc xuống đúng vị trí
        siftDown(0);

        return maxVal;
    }

    // Xây dựng Max Heap từ mảng có sẵn (Build Heap) - O(n)
    void buildHeap(int arr[], int n) {
        list.clear();
        for (int i = 0; i < n; i++) {
            list.push_back(arr[i]);
        }

        // Vun từ nút cha cuối cùng (size/2 - 1) ngược về gốc (0)
        for (int i = list.size() / 2 - 1; i >= 0; i--) {
            siftDown(i);
        }
    }

    // In toàn bộ các phần tử của Max Heap
    void printHeap() {
        if (empty()) {
            cout << "Heap rong!" << endl;
            return;
        }
        list.print();
    }
};

// ========================================================
// THUẬT TOÁN HEAP SORT
// Sử dụng các hàm buildHeap và extractMax của MaxHeap
// ========================================================
void heapSort(int arr[], int n) {
    MaxHeap heap;

    // Bước 1: Xây dựng Max Heap từ mảng ban đầu
    heap.buildHeap(arr, n);

    // Bước 2: Lần lượt trích xuất phần tử lớn nhất đưa về cuối mảng
    // (Vì extractMax trả về giá trị lớn nhất, nên điền từ n - 1 về 0 sẽ được mảng tăng dần)
    for (int i = n - 1; i >= 0; i--) {
        arr[i] = heap.extractMax();
    }
}

// ========================================================
// HÀM MAIN KIỂM THỬ
// ========================================================
int main() {
    int array[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(array) / sizeof(array[0]);

    cout << "Mang ban dau: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Gọi hàm heapSort
    heapSort(array, n);

    cout << "Mang sau khi Heap Sort: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
