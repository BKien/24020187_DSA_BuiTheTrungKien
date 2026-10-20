#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

// Cài đặt Danh sách (List) dựa trên mảng
const int MAX = 1000;

class List {
private:
    int a[MAX];     // Mảng lưu trữ các phần tử
    int n;          // Số lượng phần tử hiện tại

public:
    // Khởi tạo danh sách rỗng
    List() {
        n = 0;
    }

    // Kiểm tra danh sách rỗng
    bool empty() {
        return n == 0;
    }

    // Kiểm tra danh sách đã đầy chưa
    bool full() {
        return n == MAX;
    }

    // Lấy số lượng phần tử hiện có
    int size() {
        return n;
    }

    // Lấy giá trị phần tử tại vị trí index (0 <= index < n)
    int get(int index) {
        if (index < 0 || index >= n) {
            cout << "Vi tri khong hop le!" << endl;
            return -1;
        }
        return a[index];
    }

    // Thêm phần tử vào cuối danh sách - O(1)
    void push_back(int val) {
        if (full()) {
            cout << "Danh sach da day!" << endl;
            return;
        }
        a[n] = val;
        n++;
    }

    // Chèn phần tử val vào vị trí index (0 <= index <= n) - O(n)
    void insert(int index, int val) {
        if (full()) {
            cout << "Danh sach da day!" << endl;
            return;
        }
        if (index < 0 || index > n) {
            cout << "Vi tri chen khong hop le!" << endl;
            return;
        }
        for (int i = n; i > index; i--) {
            a[i] = a[i - 1];
        }
        a[index] = val;
        n++;
    }

    // Thêm phần tử vào đầu danh sách - O(n)
    void push_front(int val) {
        insert(0, val);
    }

    // Xóa phần tử tại vị trí index (0 <= index < n) - O(n)
    void removeAt(int index) {
        if (index < 0 || index >= n) {
            cout << "Vi tri xoa khong hop le!" << endl;
            return;
        }
        for (int i = index; i < n - 1; i++) {
            a[i] = a[i + 1];
        }
        n--;
    }

    // Xóa phần tử ở đầu danh sách - O(n)
    void pop_front() {
        removeAt(0);
    }

    // Xóa phần tử ở cuối danh sách - O(1)
    void pop_back() {
        if (empty()) {
            cout << "Danh sach rong!" << endl;
            return;
        }
        n--;
    }

    // Tìm kiếm phần tử có giá trị val, trả về vị trí index đầu tiên (-1 nếu không thấy) - O(n)
    int find(int val) {
        for (int i = 0; i < n; i++) {
            if (a[i] == val) {
                return i;
            }
        }
        return -1;
    }

    // In toàn bộ danh sách
    void print() {
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    // Xóa toàn bộ danh sách
    void clear() {
        n = 0;
    }
};

#endif // LIST_H
