#include "List.h"
#include <iostream>
using namespace std;

class Queue {
    List list;
    bool isEmpty(){
        return list.empty();
    }
    void enqueue(int value){
        list.push_back(value);
    }
    int dequeue(){
        int result = list.get(0);
        list.removeAt(0);
        return result;
    }
    int peak(){
        return list.get(0);
    }
    int size(){
        return list.size();
    }
};

int main() {
    
}
