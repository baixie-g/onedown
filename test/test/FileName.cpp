#include<iostream>
using namespace std;
//#pragma once
//#include<iostream>

//using namespace std;

template<typename T>
struct Node
{
	Node<T>* next = NULL;
	T date = 0;
};

template<typename T>
class Queue
{
public:
	Node<T>* head = NULL;
	int n;//栈中元素的数量（不包括头节点）
public:
	Queue();
	Queue(const Queue<T>& s);
	~Queue();
	void push(T m);//增加元素
	void pop();//删除
	void pop_n(int m);//删除指定位置的元素
	T get_last();//得到栈顶的数
	T get(int m);//栈中特定的数据
	int get_n();//得到栈中特定位置的元素
	void change(int k, T m);//将栈中特定位置的元素的值改为特定的值
	Queue<T> add(const Queue<T>& Queue_2);
	Queue<T> substract(const Queue<T>& Queue_2);
	Queue<T> multiply(const Queue<T>& Queue_2);
	Queue<T>& operator=(const Queue<T>& Q);
	Queue<T> operator+(const Queue<T>& Q2);
	Queue<T> operator-(const Queue<T>& Q2);
	Queue<T> operator*(const Queue<T>& Q2);
	//	friend ostream& operator<<(ostream& out, const Queue<T>& Q);
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
	this->head = nullptr;
	this->n = 0;
	Node<T>* t_1 = s.head;
	Node<T>* t_2 = this->head;
	while (t_1)
	{
		t_2->next = new Node<T>;
		t_2->next->date = t_1->next->date;
		t_1 = t_1->next;
		t_2 = t_2->next;
	}
	t_2->next = NULL;
}

template<typename T>
Queue<T>::~Queue()
{
	while (head->next)
	{
		Node<T>* u = head->next->next;
		delete head->next;
		head = u;
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
T Queue<T>::get_last()
{
	Node<T>* t = head;
	while (t->next)
		t = t->next;
	return t->date;
}
template<typename T>
int Queue<T>::get_n()
{
	return  n;
}

template<typename T>
void Queue<T>::change(int k, T m)
{
	Node<T>* t = head;
	for (int i = 0; i < k + 1; i++)
		t = t->next;
	t->date = m;
}

template<typename T>
T Queue<T>::get(int m)
{
	Node<T>* t = head;
	for (int i = 0; i < m + 1; i++)
		t = t->next;
	return t->date;
}

template<typename T>
void Queue<T>::pop()
{
	Node<T>* t = head;
	while (t->next->next)
		t = t->next;
	n--;
	delete t->next;
	t->next = NULL;
}

template<typename T>
void Queue<T>::pop_n(int m)
{
	Node<T>* t_1 = head;
	Node<T>* t_2 = NULL;
	for (int i = 0; i < m; i++)
	{
		t_2 = t_1;
		t_1 = t_1->next;
	}
	Node<T>* t = t_2->next;
	t_2->next = t_1->next;
	delete t;
	n--;
}

template<typename T>
Queue<T> Queue<T>::add(const Queue<T>& Queue_2)
{
	Node<T>* t_1 = head;
	for (int i = 0; i < n; i++)
	{
		int count = 1;
		Node<T>* t_2 = Queue_2.head;
		t_1 = t_1->next;
		for (int i = 0; i < Queue_2.n; i++)
		{
			t_2 = t_2->next;
			if (t_1->date == t_2->date)
			{
				Node<T>* t = head;
				Node<T>* u = NULL;
				for (int i = 0; i < count; i++)
				{
					u = t;
					t = t->next;
				}
				Node<T>* k = u->next;
				u->next = t->next;
				delete k;
				(this->n)--;
			}
			count++;
		}
	}
	Queue temp;
	t_1 = head;
	Node<T>* u = temp.head;
	while (t_1!=nullptr)
	{
		
		Node<T>* p = new Node<T>;
		p->date = t_1->date;
		u->next = p;
		p->next = NULL;
		temp.n++;
		t_1 = t_1->next;
	}
	u = temp.head;
	t_1 = Queue_2.head;
	while (u->next)
		u = u->next;
	u->next = t_1->next;
	temp.n = temp.n + Queue_2.n;
	delete t_1;
	return temp;
}
//差集
template<typename T>
Queue<T> Queue<T>::substract(const Queue<T>& Queue_2)
{
	Node<T>* t_1 = this->head;
	Queue temp;
	for (int i = 0; i < n; i++)
	{
		Node<T>* t_2 = Queue_2.head;
		t_1 = t_1->next;
		bool flag = true;
		for (int i = 0; i < Queue_2.n; i++)
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
	Queue temp;
	Node<T>* t_1 = head;
	Node<T>* t_2 = Queue_2.head;
	for (int i = 0; i < n; i++)
	{
		t_1 = t_1->next;
		for (int i = 0; i < Queue_2.n; i++)
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
		Node<T>* t = head->next;
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
/*假设链表表示集合。已知两个集合A、B，设计算法以求解C = A + B（并集），  C = A * B（交集），A = A - B（差集）
要求重载运算符，+、*、-、=、<<；并分析算法的时间复杂度、空间复杂度。*/
int main()
{
	Queue<int> q1;
	Queue<int> q2;
	Queue<int> q3;
	int n = 2, m = 2, t = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		q1.push(t);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> t;
		q2.push(t);
	}
	q3 = q1 + q2;
	//	cout << q3;
	q3 = q3 * q1;
	//	cout << q3;
	q1 = q1 - q2;
	//	cout << q1;

	return 0;
}






//
//long long count(int n, int k) {
//    if (n < k) {
//        return 0;
//    }
//    if (n == k) {
//        return 1;
//    }
//    long long ans = 0;
//    for (int i = k; i <= n; i++) {
//        ans += count(n - i, k);
//    }
//    return ans;
//}
//
//int main() {
//    int n, k;
//    cin >> n >> k;
//    cout << count(n, k) << endl;
//    return 0;
//}
//int main() {
//	while (1){int n,a=1;
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		a *= 2;
//	}
//		
//	cout << a << endl;;
//	cout << a % 5000011 << endl;;
//
//	}
//	
//}