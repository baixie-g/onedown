//#include<iostream>
//
//using namespace std;
//
//struct node
//{
//	int data=0;
//	node* q;
//	node* h;
//	node(int a) : data(a) {};
//};
//class list {
//public:
//	node* head=NULL;
//	list(){};
//	void add(int a) {
//		if (!head) {
//			node* t = new node(a);
//			t->h = t;
//			t->q = t;
//			head = t;
//			return;
//		}
//		node* t = new node(a);
//		t->q = head->q;
//		head->q->h = t;
//		t->h = head;
//		head->q = t;
//	}
//	node* del(int a,node* x) {
//		if (a < 0) {
//			for (int i = 0; i < -a-1; i++)
//			{
//				x = x->q;
//			}
//			cout << x->data << endl;
//			node* r = x->q;
//			x->q->h = x->h;
//			x->h->q = x->q;
//			delete x;
//			return r;
//		}
//		else
//		{
//			for (int i = 0; i < a - 1; i++)
//			{
//				x= x->h;
//			}cout << x->data << endl;
//			node* r = x->h;
//			x->q->h = x->h;
//			x->h->q = x->q;
//			delete x;
//			return r;
//		}
//	}
//	void p() {
//		node* a=head;
//		do
//		{
//			cout << a->data << endl;
//			a = a->h;
//		} while (a!=head);
//	}
//};
//int main() {
//	list a;
//	for (int i = 0; i < 30; i++)
//	{
//		a.add(i+1);
//	}
//	a.p();
//	node* k=a.head;
//	for (int i = 0; i < 7; i++)
//	{
//		k=a.del(-5,a.del(9, k));
//	}
//	a.del(9, k);
//
//}

#include<iostream>
#include<vector>

using namespace std;

class ar {
public:
	vector<int> arr;
	int size=0;
	ar() {}

	void add(int a) {
		arr.push_back(a);
		size++;
	}

	int del(int a, int index) {
		if (a>0)
			index = index + a - 1;
		else
			index = index + a + 1;
		index %= size;
		if (index < 0)
			index += size;
		cout << arr[index] << endl;
		arr.erase(arr.begin() + index);
		size--;
		if (a>0)
			return index;
		else
			return index - 1;
		
	}

	void p() {
		for (int num : arr) {
			cout << num << endl;
		}
	}
};

int main() {
	ar a;

	for (int i = 0; i < 30; i++) {
		a.add(i + 1);
	}

	a.p();

	int index = 0;

	for (int i = 0; i < 7; i++) {
		index = a.del(9, index);
		index = a.del(-5, index);
	}

	a.del(9, index);

	return 0;
}
