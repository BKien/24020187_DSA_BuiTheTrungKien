#include "List.h"
#include <iostream>
using namespace std;

class Stack {
public:
    List list;
    void push(int value){
        list.push_back(value);
    }
    int pop(){
        int result = list.get(list.size()-1);
        list.pop_back();
        return result;
    }
    bool isEmpty(){
        return list.empty();
    }
    int top(){
        return list.get(list.size()-1);
    }
    int size(){
        return list.size();
    }
};