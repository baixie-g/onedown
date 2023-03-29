#include <iostream>
#include"stack.h"
using namespace std;

//Ĭ�Ϲ��캯��
template <typename T>
Stack<T>::Stack() {
    cap = 0;
    current = -1;
    arr = nullptr;
}

//һ�㹹�캯��
template <typename T>
Stack<T>::Stack(int n) {
    cap = n;
    current = -1;
    arr = new T[n]{};
}

//�������캯��(ǰǳ��)
template <typename T>
Stack<T>::Stack(Stack<T>& stack) {
    cap = stack.capciaty();
    current = stack.size();
    this->arr = stack.arr;
}

//��������
template <typename T>
Stack<T>::~Stack() {
    if (cap == 0) {
        return;
    }
    cap = 0;
    current = -1;
    delete[] arr;
    arr = nullptr;
}

//����ջ��
template <typename T>
T& Stack<T>::top() {
    if (is_empty()) {
        cout << "[error]: stack has no element" << endl;
    }
    return *(arr + current);
}

//��ջ�����һ��Ԫ��
template <typename T>
Stack<T>& Stack<T>::push(const T& elem) {
    if (is_full()) {
        reserve(2 * cap);
    }
    current++;
    arr[current] = elem;
    return *this;
}

//ջ������
template <typename T>
Stack<T>& Stack<T>::pop() {
    if (is_empty()) {
        cout << "[error]: don't try to pop a empty stack" << endl;
        return *this;
    }
    current--;
    return *this;
}

//��������
template <typename T>
void Stack<T>::reserve(int num) {
    if (num < cap) {
        cout << "[warning]: input of reserve() function shuold lager than capciaty" << endl;
        return;
    }
    T* arr_ = new T[num]{};
    for (int i = 0; i <= current; i++)
        arr_[i] = arr[i];
    delete[] arr;
    arr = arr_;
    arr_ = nullptr;
    cap = num;
}
