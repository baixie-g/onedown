#pragma once
#include<iostream>
using namespace std;
class Queue {
private:
    int* data; // ��������
    int front; // ����ָ��
    int rear; // ��βָ��
    int size; // ���д�С
public:
    Queue(int n); // ���캯������ʼ������
    ~Queue(); // �����������ͷſռ�
    bool isEmpty(); // �ж϶����Ƿ�Ϊ��
    bool isFull(); // �ж϶����Ƿ���
    void enqueue(int x); // ��Ӳ���
    int dequeue(); // ���Ӳ���
    int getFront();//��ȡ��Ԫ��
};
Queue::Queue(int n) {
    data = new int[n]; // ��̬����ռ�
    front = rear = 0; // ��ʼ��ָ��Ϊ0
    size = n; // ��¼���д�С
}
Queue::~Queue() {
    delete[] data; // �ͷſռ�
}
bool Queue::isEmpty() {
    return front == rear; // ���ָ����ȣ���Ϊ��
}
bool Queue::isFull() {
    return (rear + 1) % size == front; // �����һ��λ����front����Ϊ����ѭ�����У�
}
void Queue::enqueue(int x) {
    if (isFull()) { // ����Ƿ����ˣ���������򱨴��˳�����
        cerr << "The queue is full!" << endl;
        exit(1);
    }
    data[rear] = x; // ��Ԫ�ط����βλ��
    rear = (rear + 1) % size; // ���¶�βָ�루ѭ����
}
int Queue::dequeue() {
    if (isEmpty()) { // ����Ƿ���ˣ���������򱨴��˳�����
        cerr << "The queue is empty!" << endl;
        exit(1);
    }
    int x = data[front]; // ȡ������Ԫ�ز����浽x��
    front = (front + 1) % size; // ���¶���ָ�루ѭ����
    return x;

}
int Queue::getFront() {
    if (isEmpty()) { // ����Ƿ���ˣ���������򱨴��˳�����
        cerr << "The queue is empty!" << endl;
        exit(1);
    }
    return data[front]; // ���ض���Ԫ��
}