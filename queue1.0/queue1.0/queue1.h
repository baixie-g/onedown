#pragma once
#include <iostream>
#include <string>
    using namespace std;

const int MAX_SIZE = 100;

class Queue {
private:
    int arr[MAX_SIZE];
    int front, rear;
public:
    Queue() {
        front = rear = -1;
    }
    bool isEmpty() {
        return front == -1 && rear == -1;
    }
    bool isFull() {
        return rear == MAX_SIZE - 1;
    }
    void enqueue(int val) {
        if (isFull()) {
            cout << "队列已满\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear++;
        }
        arr[rear] = val;
    }
    int dequeue() {
        if (isEmpty()) {
            cout << "队列为空\n";
            return -1;
        }
        int val = arr[front];
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front++;
        }
        return val;
    }
    void printQueue() {
        if (isEmpty()) {
            cout << "队列为空\n";
            return;
        }
        cout << "队列: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int peek() {
        if (isEmpty()) {
            // 如果队列为空，抛出异常
            throw std::runtime_error("Queue is empty");
        }

        return arr[front]; // 返回队头元素
    }
    int _size() {
        return (rear - front + 1);
    }
};
