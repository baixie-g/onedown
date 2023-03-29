#pragma once
#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

class QueueByList
{
	Node *front;
	Node *rear;
	public:
		QueueByList();
		~QueueByList();
		void enqueue(int);
		int dequeue();
		void display();
		bool isEmpty();
};
QueueByList::QueueByList()
{
	front = NULL;
	rear = NULL;
}
QueueByList::~QueueByList()
{
	Node *temp;
	while (front != NULL)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
	rear = NULL;
}
void QueueByList::enqueue(int value)
{
	Node *temp = new Node;
	temp->data = value;
	temp->next = NULL;
	if (front == NULL)
	{
		front = temp;
		rear = temp;
	}
	else
	{
		rear->next = temp;
		rear = temp;
	}
}
int QueueByList::dequeue()
{
	int value = -1;
	if (front == NULL)
	{
		cout << "Queue is empty" << endl;
	}
	else
	{
		Node *temp = front;
		value = temp->data;
		front = front->next;
		delete temp;
	}
	return value;
}
void QueueByList::display()
{
	if (front == NULL)
	{
		cout << "Queue is empty" << endl;
	}
	else
	{
		Node *temp = front;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
}
bool QueueByList::isEmpty()
{
	if (front == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}