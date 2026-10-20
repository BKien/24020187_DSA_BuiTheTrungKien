#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
    LinkedList list;

    // 1. Them phan tu
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_front(5);
    list.insert(2, 15); // chen 15 vao vi tri index 2

    cout << "Danh sach sau khi them: ";
    list.print(); // 5 -> 10 -> 15 -> 20 -> 30 -> NULL

    // 2. Truy cap va tim kiem
    cout << "Phan tu tai index 2: " << list.get(2) << endl;
    cout << "Vi tri cua gia tri 20: " << list.find(20) << endl;

    // 3. Xoa phan tu
    list.pop_front();   // xoa dau (5)
    list.pop_back();    // xoa cuoi (30)
    list.removeAt(1);   // xoa tai index 1 (15)

    cout << "Danh sach sau khi xoa: ";
    list.print(); // 10 -> 20 -> NULL

    // 4. Kich thuoc va kiem tra rong
    cout << "So luong phan tu: " << list.size() << endl;
    cout << "Danh sach co rong khong: " << (list.empty() ? "Co" : "Khong") << endl;

    return 0;
}
