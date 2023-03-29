#pragma once
#include<iostream>
using namespace std;
class Queue {
private:
    int* data; // 队列数据
    int front; // 队首指针
    int rear; // 队尾指针
    int size; // 队列大小
public:
    Queue(int n); // 构造函数，初始化队列
    ~Queue(); // 析构函数，释放空间
    bool isEmpty(); // 判断队列是否为空
    bool isFull(); // 判断队列是否满
    void enqueue(int x); // 入队操作
    int dequeue(); // 出队操作
    int getFront();//获取首元素
};
Queue::Queue(int n) {
    data = new int[n]; // 动态分配空间
    front = rear = 0; // 初始化指针为0
    size = n; // 记录队列大小
}
Queue::~Queue() {
    delete[] data; // 释放空间
}
bool Queue::isEmpty() {
    return front == rear; // 如果指针相等，则为空
}
bool Queue::isFull() {
    return (rear + 1) % size == front; // 如果下一个位置是front，则为满（循环队列）
}
void Queue::enqueue(int x) {
    if (isFull()) { // 检查是否满了，如果满了则报错并退出程序
        cerr << "The queue is full!" << endl;
        exit(1);
    }
    data[rear] = x; // 将元素放入队尾位置
    rear = (rear + 1) % size; // 更新队尾指针（循环）
}
int Queue::dequeue() {
    if (isEmpty()) { // 检查是否空了，如果空了则报错并退出程序
        cerr << "The queue is empty!" << endl;
        exit(1);
    }
    int x = data[front]; // 取出队首元素并保存到x中
    front = (front + 1) % size; // 更新队首指针（循环）
    return x;

}
int Queue::getFront() {
    if (isEmpty()) { // 检查是否空了，如果空了则报错并退出程序
        cerr << "The queue is empty!" << endl;
        exit(1);
    }
    return data[front]; // 返回队首元素
}