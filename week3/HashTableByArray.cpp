#include <iostream>
using namespace std;

const int SIZE = 5;


struct Node {
    int key = -1;   
    int value = -1;
};


int hashFunction(Node array[], int key) {
    int index = (key % SIZE + SIZE) % SIZE; 
    int count = 0; // đếm số phần tử trong mảng 

    bool isHash = false;
    
    while (isHash == false && count < SIZE) {
        // Dừng khi gặp ô trống (-1) HOẶC ô đã chứa chính key này
        if (array[index].key == -1 || array[index].key == key) {
            isHash = true;
            break;
        }
        index = (index + 1) % SIZE; // Dò tuyến tính có xoay vòng
        count++;
    }

    if (!isHash) {
        return -1; // Bảng đã đầy
    }
    return index;
}

void add(Node array[], int key, int value) {
    int index = hashFunction(array, key);
    if (index == -1) {
        cout << "Bang bam da day, khong the them key: " << key << endl;
        return;
    }
    array[index].key = key;
    array[index].value = value;
}

int get(Node array[], int key) {
    int index = hashFunction(array, key);
    // Nếu tìm thấy đúng vị trí chứa key thì trả về value
    if (index != -1 && array[index].key == key) {
        return array[index].value;
    }
    return -1; // Không tìm thấy
}

int main() {

    return 0;
}
