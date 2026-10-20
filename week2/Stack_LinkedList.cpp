#include "LinkedList.h"
#include <iostream>
using namespace std;
struct Stack{
    LinkedList head;
    void push(int value){
        head.push_front(value);
    }

    int pop(){
        int result = head.get(0);
        head.removeAt(0);
        return result; 
    }

    bool isEmpty(){
        return head.empty();
    }

    void top(){
        cout<<head.get(0);
    }

    int size(){
        return head.size();
    }
    
    void print(){
        head.print();
    }
};

int main(){
    Stack stack;
    
    stack.print();
}