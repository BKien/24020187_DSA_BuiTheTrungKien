#include "LinkedList.h"
#include <iostream>
using namespace std;
class Queue {
public:
    LinkedList head;
    bool isEmpty(){
        return head.empty();
    }
    void enqueue(int value){
        head.push_back(value);
    }
    int dequeue(){
        int result = head.get(0);
        head.removeAt(0);
        return result;
    }
    int peak(){
        return head.get(0);
    }
    int size(){
        return head.size();
    }
};