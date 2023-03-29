#pragma once
#pragma once
#include<iostream>

using namespace std;

template<typename T>
struct Node
{T date = 0;
	Node<T>* next = NULL;
	
};

template<typename T>
class Queue
{
private:
	Node<T>* head;
	int n;//栈中元素的数量（不包括头节点）
public:
	Queue();
	Queue(const Queue<T>& s);
	~Queue();
	void push(T m);//增加元素
	Queue<T> add(const Queue<T>& Queue_2);
	Queue<T> substract(const Queue<T>& Queue_2);
	Queue<T> multiply(const Queue<T>& Queue_2);
	Queue<T>& operator=(const Queue<T>& Q);
	Queue<T> operator+(const Queue<T>& Q2);
	Queue<T> operator-(const Queue<T>& Q2);
	Queue<T> operator*(const Queue<T>& Q2);
	void print()const;
	//friend ostream& operator<<(ostream& out, const Queue<T>& Q);
};

template<typename T>
Queue<T>::Queue()
{
	head = new Node<T>;
	head->next = NULL;
	n = 0;
}

template<typename T>
Queue<T>::Queue(const Queue<T>& s)
{
	Node<T>* t_1 = s.head->next;
	this->head = new Node<T>;
	this->head->next = NULL;
	Node<T>* t_2 = this->head;
	n = 0;
	while (t_1)
	{
		Node<T>* p = new Node<T>;
		p->date = t_1->date;
		t_2->next = p;
		t_1 = t_1->next;
		t_2 = t_2->next;
		n++;
	}
}

template<typename T>
Queue<T>::~Queue()
{
	Node<T>* t = this->head;
	while (t->next)
	{
		cout << t->next << " ";
		t = t->next;
	}
	while (this->head->next)
	{
		Node<T>* u = head->next->next;
		delete head->next;
		head->next = u;
	}
	delete head;
}

template<typename T>
void Queue<T>::push(T m)
{
	Node<T>* p = new Node<T>;
	p->date = m;
	Node<T>* t = head;
	while (t->next)
		t = t->next;
	t->next = p;
	p->next = NULL;
	n++;
}

template<typename T>
Queue<T> Queue<T>::add(const Queue<T>& Queue_2)
{
	Node<T>* u = Queue_2.head;
	Node<T>* m = NULL;
	for (int i = 0; i < Queue_2.n; i++)
	{
		Node<T>* k = u;
		u = u->next;
		Node<T>* t = this->head;
		for (int j = 0; j < this->n; j++)
		{
			t = t->next;
			if (u->date == t->date)
			{
				k->next = u->next;
				m = u;
				u = k;
				delete m;
			}
		}
	}
	m = this->head;
	u = Queue_2.head;
	while (m->next)
		m = m->next;
	m->next = u->next;
	delete u;
	Queue<T> temp = *this;
	Node<T>* t = temp.head;
	while (t->next)
	{
		cout << t->next << " ";
		t = t->next;
	}
	return temp;

}
//差集
template<typename T>
Queue<T> Queue<T>::substract(const Queue<T>& Queue_2)
{
	Node<T>* t_1 = this->head;
	Queue<T> temp;
	for (int i = 0; i < this->n; i++)
	{
		Node<T>* t_2 = Queue_2.head;
		t_1 = t_1->next;
		bool flag = true;
		for (int j = 0; j < Queue_2.n; j++)
		{
			t_2 = t_2->next;
			if (t_1->date == t_2->date)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			temp.push(t_1->date);
			temp.n++;
		}
	}
	return temp;

}

template<typename T>
Queue<T> Queue<T>::multiply(const Queue<T>& Queue_2)
{
	Queue<T> temp;
	Node<T>* t_1 = this->head;
	Node<T>* t_2 = Queue_2.head;
	for (int i = 0; i < this->n; i++)
	{
		t_1 = t_1->next;
		for (int j = 0; j < Queue_2.n; j++)
		{
			t_2 = t_2->next;
			if (t_1->date == t_2->date)
			{
				temp.push(t_1->date);
				temp.n++;
			}
		}
	}
	return temp;
}

template<typename T>
Queue<T>& Queue<T>:: operator=(const Queue<T>& Q)
{
	if (this != &Q)
	{
		n = Q.n;
		Node<T>* t = this->head->next;
		Node<T>* u = Q.head->next;
		while (u)
		{
			Node<T>* p = new Node<T>;
			p->date = u->date;
			t = p;
			p->next = NULL;
			t = t->next;
			u = u->next;
		}
	}
	return *this;
}

template<typename T>
void Queue<T>::print()const
{
	Node<T>* t = this->head->next;
	while (t)
	{
		cout << t->date << " ";
		t = t->next;
	}
}

//template<typename T>
//ostream& operator<<(ostream& out, const Queue<T>& Q)
//{
//	Node<T>* t = Q.head->next;
//	while (t)
//	{
//		out << t->date << " ";
//		t = t->next;
//	}
//	return out;
//}

template<typename T>
Queue<T> Queue<T>::operator+(const Queue<T>& Q2)
{
	return this->add(Q2);
}

template<typename T>
Queue<T> Queue<T>::operator-(const Queue<T>& Q2)
{
	return this->substract(Q2);
}

template<typename T>
Queue<T> Queue<T>::operator*(const Queue<T>& Q2)
{
	return this->multiply(Q2);
}