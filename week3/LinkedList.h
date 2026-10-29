#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

// Dinh nghia nut (Node) trong Danh sach lien ket don
struct Node {
    int data;
    int key;       // Du lieu cua nut
    Node* next;     // Con tro tro den nut tiep theo

    Node(int val) {
        data = val;
        next = nullptr;
    }
    Node(int val,int k){
        data = val;
        key = k;
    }
};

// Cai dat Danh sach lien ket don (LinkedList)
class LinkedList {
private:
    Node* head;     // Con tro tro den nut dau tien
    int n;          // So luong phan tu hien tai

public:
    // Khoi tao danh sach rong
    LinkedList() {
        head = nullptr;
        n = 0;
    }

    // Ham huy: giai phong toan bo bo nho cac nut khi ket thuc
    ~LinkedList() {
        clear();
    }

    // Kiem tra danh sach rong
    bool empty() {
        return head == nullptr;
    }

    // Lay so luong phan tu
    int size() {
        return n;
    }

    // Lay gia tri phan tu tai vi tri index (0 <= index < n) - O(n)
    int get(int index) {
        if (index < 0 || index >= n) {
            cout << "Vi tri khong hop le!" << endl;
            return -1;
        }
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    // Them phan tu vao dau danh sach - O(1)
    void push_front(int val,int key) {
        Node* newNode = new Node(val,key);
        newNode->next = head;
        head = newNode;
        n++;
    }

    // Them phan tu vao cuoi danh sach - O(n)
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        n++;
    }

    // Chen phan tu val vao vi tri index (0 <= index <= n) - O(n)
    void insert(int index, int val) {
        if (index < 0 || index > n) {
            cout << "Vi tri chen khong hop le!" << endl;
            return;
        }
        if (index == 0) {
            return;
        }
        Node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        n++;
    }

    // Xoa phan tu o dau danh sach - O(1)
    void pop_front() {
        if (head == nullptr) {
            cout << "Danh sach rong!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        n--;
    }

    // Xoa phan tu o cuoi danh sach - O(n)
    void pop_back() {
        if (head == nullptr) {
            cout << "Danh sach rong!" << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            n = 0;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        n--;
    }

    // Xoa phan tu tai vi tri index (0 <= index < n) - O(n)
    void removeAt(int index) {
        if (index < 0 || index >= n) {
            cout << "Vi tri xoa khong hop le!" << endl;
            return;
        }
        if (index == 0) {
            pop_front();
            return;
        }
        Node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
        n--;
    }

    // Tim kiem phan tu co gia tri val, tra ve index dau tien (-1 neu khong tim thay) - O(n)
    int find(int val) {
        Node* temp = head;
        int idx = 0;
        while (temp != nullptr) {
            if (temp->data == val) {
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }

    // Tim kiem phan tu theo key, tra ve vi tri index dau tien (-1 neu khong tim thay) - O(n)
    int findByKey(int k) {
        Node* temp = head;
        int idx = 0;
        while (temp != nullptr) {
            if (temp->key == k) {
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }

    // Lay truc tiep gia tri (data) theo key (-1 neu khong tim thay) - O(n)
    int getByKey(int k) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->key == k) {
                return temp->data;
            }
            temp = temp->next;
        }
        return -1;
    }

    // In toan bo danh sach lien ket
    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Xoa toan bo danh sach va giai phong bo nho
    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        n = 0;
    }
};

#endif // LINKEDLIST_H
