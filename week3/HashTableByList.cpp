#include <iostream>
#include <array>
#include "LinkedList.h"
using namespace std;

int hashFunction(int key) {
    int index = key % 5;
    return index;
}

void add(LinkedList table[], int key, int value) {
    int index = hashFunction(key);
    table[index].push_front(value, key);
}

int get(LinkedList table[], int key) {
    int index = hashFunction(key);
    return table[index].getByKey(key);
}

int main() {

    return 0;
}
