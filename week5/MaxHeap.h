#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include "ArrayList.h"
#include <iostream>
using namespace std;

class MaxHeap {
private:
    ArrayList list; // Cấu trúc danh sách mảng lưu trữ các nút của Heap

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
    // Dùng khi thêm (insert) một phần tử mới vào cuối Heap
    void siftUp(int i) {
        while (i > 0 && list.get(i) > list.get(parent(i))) {
            swapElements(i, parent(i));
            i = parent(i); // Tiếp tục di chuyển lên node cha
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

    // Xem giá trị lớn nhất (ở đỉnh heap, tức phần tử đầu tiên của ArrayList) - O(1)
    int getMax() {
        if (empty()) {
            cout << "Heap dang rong!" << endl;
            return -1;
        }
        return list.get(0);
    }

    // Thêm một phần tử vào Max Heap - O(log n)
    void insert(int val) {
        // Bước 1: Thêm phần tử mới vào cuối danh sách mảng
        list.push_back(val);

        // Bước 2: Vun phần tử vừa thêm lên đúng vị trí
        siftUp(list.size() - 1);
    }

    // Lấy và xóa phần tử lớn nhất ra khỏi Max Heap - O(log n)
    int extractMax() {
        if (empty()) {
            cout << "Heap dang rong!" << endl;
            return -1;
        }

        int maxVal = list.get(0); // Giá trị lớn nhất ở đỉnh

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

#endif // MAX_HEAP_H
