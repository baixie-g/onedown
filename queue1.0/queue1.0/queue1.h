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
            cout << "��������\n";
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
            cout << "����Ϊ��\n";
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
            cout << "����Ϊ��\n";
            return;
        }
        cout << "����: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int peek() {
        if (isEmpty()) {
            // �������Ϊ�գ��׳��쳣
            throw std::runtime_error("Queue is empty");
        }

        return arr[front]; // ���ض�ͷԪ��
    }
    int _size() {
        return (rear - front + 1);
    }
};
