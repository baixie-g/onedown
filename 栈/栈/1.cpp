#include<iostream>
using namespace std;
//template<class elementtype>
#define maxlen 10;
class stack {
private:
	int count;
	int* data;
public:
	stack() {
		data = new int[maxlen];
		count = 0;
		if (!data)
		{
			cout << "data malloc error!" << endl;
		}
	};
	~stack()
	{
		if (data)
		{
			delete[] data;
			data = NULL;
		}
	}
	bool empty() {
		if (count)
			return false;
		else
			return true;
	};//const;
	bool full() {
		if (count == maxlen) {
			return true;
		};
		return false;

	};//const;
	bool get_top(int& x) {
		if (empty())return 0;
		else {
			x = date[count - 1];
			return 1;
		}

	};//const
	bool push(int x) {
		if (full())return 0;
		date[count] = x;
		count++;
		return 1;
	};
	bool pop() {
		if (empty())return 0;
		count--;
		return 1;
	};
	void show() {
		if (count == 0) {
			cout << "¿Õ" << endl;
			return;
		}
		cout << "´Ë´¦Õ»µ×" << endl;
		for (int i = 0; i < count; i++)cout << data[i] << "\n";
		return;
	}

};

int main() {
	int x;
	cin >> x;
	//stack<int>* a = new stack<int>();
	stack* a = new stack();
	a->push(x);
	a->show();
}
