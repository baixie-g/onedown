#include<iostream>
#include"stack.h"
#include"stack.cpp"
using namespace std;
int main() {
    Stack<int> stack(3);

    cout << "top=" << stack.top() << ", ����=" << stack.capciaty() << ", Ԫ�ظ���=" << stack.size() << endl;
    stack.push(3);
    cout << "top=" << stack.top() << ", ����=" << stack.capciaty() << ", Ԫ�ظ���=" << stack.size() << endl;
    stack.push(2);
    cout << "top=" << stack.top() << ", ����=" << stack.capciaty() << ", Ԫ�ظ���=" << stack.size() << endl;
    stack.push(5);
    cout << "top=" << stack.top() << ", ����=" << stack.capciaty() << ", Ԫ�ظ���=" << stack.size() << endl;
    stack.push(5);
    cout << "top=" << stack.top() << ", ����=" << stack.capciaty() << ", Ԫ�ظ���=" << stack.size() << endl;
    stack.pop();
    cout << "top=" << stack.top() << ", ����=" << stack.capciaty() << ", Ԫ�ظ���=" << stack.size() << endl;
    stack.clear();
}