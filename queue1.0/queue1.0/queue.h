#pragma once
#include<iostream>
using namespace std;

// 定义一个模板类 Queue
template <class T>
class Queue {
    // 定义一个动态数组 data 用来存储元素
    T* data;
    // 定义一个变量 size 用来记录队列的大小
    int size;
    // 定义两个变量 front 和 rear 用来指示队列的头部和尾部
    int front, rear;
public:
    // 构造函数，初始化队列为空
    Queue() {
        data = nullptr;
        size = 0;
        front = rear = -1;
    }

    // 析构函数，释放动态数组的内存
    ~Queue() {
        delete[] data;
    }
    int _size() {
        return this->size;
    }

    // 判断队列是否为空
    bool isEmpty() {
        return front == -1;
    }

    // 判断队列是否已满
    bool isFull() {
        return (rear + 1) % size == front;
    }

    // 入队操作，将元素 x 插入到队尾
    void enqueue(T x) {
        if (isFull()) {
            // 如果队列已满，需要扩展动态数组的容量，并复制原有元素到新数组中
            int oldSize = size;
            size = size ? size * 2 : 1; // 如果原大小为0，则新大小为1，否则为原大小的两倍
            T* newData = new T[size]; // 创建一个新的动态数组

            for (int i = 0; i < oldSize; i++) {
                newData[i] = data[(front + i) % oldSize]; // 复制原有元素到新数组中，注意要考虑循环的情况
            }

            delete[] data; // 删除原有动态数组
            data = newData; // 更新 data 指针

            front = 0;
            rear = oldSize - 1;
        }

        rear = (rear + 1) % size; // 更新 rear 的位置
        data[rear] = x; // 将元素 x 存入队尾

        if (front == -1) {
            front = rear; // 如果之前队列为空，则更新 front 的位置为与 rear 相同
        }
    }

    // 出队操作，将队头元素移除并返回
    T dequeue() {
        if (isEmpty()) {
            // 如果队列为空，抛出异常
            throw std::runtime_error("Queue is empty");
        }

        T x = data[front]; // 取出队头元素

        if (front == rear) {
            // 如果队列只有一个元素，则更新 front 和 rear 的位置为 -1，表示空队列
            front = rear = -1;
        }
        else {
            // 否则，更新 front 的位置为下一个元素的位置
            front = (front + 1) % size;
        }

        return x; // 返回队头元素
    }

    // 查看队头元素，不移除
    T peek() {
        if (isEmpty()) {
            // 如果队列为空，抛出异常
            throw std::runtime_error("Queue is empty");
        }

        return data[front]; // 返回队头元素
    }
};