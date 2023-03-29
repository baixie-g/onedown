#pragma once
#include<iostream>
using namespace std;

// ����һ��ģ���� Queue
template <class T>
class Queue {
    // ����һ����̬���� data �����洢Ԫ��
    T* data;
    // ����һ������ size ������¼���еĴ�С
    int size;
    // ������������ front �� rear ����ָʾ���е�ͷ����β��
    int front, rear;
public:
    // ���캯������ʼ������Ϊ��
    Queue() {
        data = nullptr;
        size = 0;
        front = rear = -1;
    }

    // �����������ͷŶ�̬������ڴ�
    ~Queue() {
        delete[] data;
    }
    int _size() {
        return this->size;
    }

    // �ж϶����Ƿ�Ϊ��
    bool isEmpty() {
        return front == -1;
    }

    // �ж϶����Ƿ�����
    bool isFull() {
        return (rear + 1) % size == front;
    }

    // ��Ӳ�������Ԫ�� x ���뵽��β
    void enqueue(T x) {
        if (isFull()) {
            // ���������������Ҫ��չ��̬�����������������ԭ��Ԫ�ص���������
            int oldSize = size;
            size = size ? size * 2 : 1; // ���ԭ��СΪ0�����´�СΪ1������Ϊԭ��С������
            T* newData = new T[size]; // ����һ���µĶ�̬����

            for (int i = 0; i < oldSize; i++) {
                newData[i] = data[(front + i) % oldSize]; // ����ԭ��Ԫ�ص��������У�ע��Ҫ����ѭ�������
            }

            delete[] data; // ɾ��ԭ�ж�̬����
            data = newData; // ���� data ָ��

            front = 0;
            rear = oldSize - 1;
        }

        rear = (rear + 1) % size; // ���� rear ��λ��
        data[rear] = x; // ��Ԫ�� x �����β

        if (front == -1) {
            front = rear; // ���֮ǰ����Ϊ�գ������ front ��λ��Ϊ�� rear ��ͬ
        }
    }

    // ���Ӳ���������ͷԪ���Ƴ�������
    T dequeue() {
        if (isEmpty()) {
            // �������Ϊ�գ��׳��쳣
            throw std::runtime_error("Queue is empty");
        }

        T x = data[front]; // ȡ����ͷԪ��

        if (front == rear) {
            // �������ֻ��һ��Ԫ�أ������ front �� rear ��λ��Ϊ -1����ʾ�ն���
            front = rear = -1;
        }
        else {
            // ���򣬸��� front ��λ��Ϊ��һ��Ԫ�ص�λ��
            front = (front + 1) % size;
        }

        return x; // ���ض�ͷԪ��
    }

    // �鿴��ͷԪ�أ����Ƴ�
    T peek() {
        if (isEmpty()) {
            // �������Ϊ�գ��׳��쳣
            throw std::runtime_error("Queue is empty");
        }

        return data[front]; // ���ض�ͷԪ��
    }
};