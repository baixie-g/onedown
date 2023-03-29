#pragma once
#include<iostream>
using namespace std;
template <typename T>
class Stack {
public:
    Stack();
    Stack(int n);
    Stack(Stack<T>& stack);
    ~Stack();
    T& top();
    Stack<T>& push(const T& elem);
    Stack<T>& pop();
    void reserve(int num);
    int size() { return current + 1; }
    int capciaty() { return cap; }
    int is_empty() { return current == -1; }
    bool is_full() { return current == (cap - 1); }
    void clear() { this->~Stack(); }
private:
    T* arr;
    int current;
    int cap;
};
