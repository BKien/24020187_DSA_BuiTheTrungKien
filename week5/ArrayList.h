#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <iostream>
using namespace std;

const int MAX = 1000;

// ========================================================
// CẤU TRÚC DỮ LIỆU DANH SÁCH MẢNG (ARRAY LIST)
// ========================================================
class ArrayList {
private:
    int a[MAX];     // Mảng tĩnh lưu trữ các phần tử
    int n;          // Số lượng phần tử hiện tại

public:
    // Khởi tạo danh sách rỗng
    ArrayList() {
        n = 0;
    }

    // Kiểm tra danh sách có rỗng không
    bool empty() {
        return n == 0;
    }

    // Kiểm tra danh sách đã đầy chưa
    bool full() {
        return n == MAX;
    }

    // Lấy số lượng phần tử hiện có trong danh sách
    int size() {
        return n;
    }

    // Lấy giá trị phần tử tại chỉ số index (0 <= index < n)
    int get(int index) {
        if (index < 0 || index >= n) {
            cout << "Chi so ngoai pham vi!" << endl;
            return -1;
        }
        return a[index];
    }

    // Gán/cập nhật giá trị tại chỉ số index
    void set(int index, int val) {
        if (index < 0 || index >= n) {
            cout << "Chi so ngoai pham vi!" << endl;
            return;
        }
        a[index] = val;
    }

    // Thêm một phần tử vào cuối danh sách - O(1)
    void push_back(int val) {
        if (full()) {
            cout << "Danh sach da day!" << endl;
            return;
        }
        a[n] = val;
        n++;
    }

    // Xóa một phần tử ở cuối danh sách - O(1)
    void pop_back() {
        if (empty()) {
            cout << "Danh sach dang rong!" << endl;
            return;
        }
        n--;
    }

    // In toàn bộ các phần tử trong danh sách
    void print() {
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    // Xóa sạch toàn bộ danh sách
    void clear() {
        n = 0;
    }
};

#endif // ARRAY_LIST_H
