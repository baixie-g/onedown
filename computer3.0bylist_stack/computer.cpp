#include<iostream>
#include<list>
#include<string>
using namespace std;

list<double> num;
list<char> ope;
string* f = new string;
int i = 0;
int xing = -2;



//此处只做判断优先级
bool priority(char a, char b)//a还没入
{
	switch (a)
	{
	case '+':
	case'-':
		if (b == '(' || b == '#')return false;
		else return true;
		break;
	case'*':
	case'/':
		if (b == '*' || b == '/')return true;
		else return false;
		break;
	case')':
		if (b == '(')return false;
		else return true;
	case'#':
		if (num.size() > 1) { return true; }
		else return false;

	}
}

void operator_in(char x) {
	switch (x)
	{
	case '#': {if (xing == -2) {
		ope.push_front('#');
		xing++;
		return;
	}
			xing++;
			break; }
	case '(':
		ope.push_front('(');
		return;
		break;
	};
	//真，运算
	while (priority(x, ope.front())) {
		double n1 = num.front();
		num.pop_front();
		double n2 = num.front();
		num.pop_front();
		double res;
		switch (ope.front())
		{
		case'*':
			res = n1 * n2;
			break;
		case'/':
			res = n2 / n1;
			break;
		case'+':
			res = n1 + n2;
			break;
		case'-':
			res = n2 - n1;
			break;
		}
		ope.pop_front();
		num.push_front(res);
	};//x还没入栈，front是栈顶
	ope.push_front(x);
	if (ope.front() == ')') { ope.pop_front(); ope.pop_front(); }
}

int main() {
	cin >> *f;
	string a = *f; int n;
	for (; i < a.length(); i++) {
		if ((char)(*f).at(i) >= '0') {
			n = (*f).at(i) - '0';
			if ((char)(*f).at(i - 1) >= '0') {
				n = (static_cast<int>(a.at(i - 1)) - 48) * 10 + (static_cast<int>(a.at(i)) - 48);
				num.pop_front();
			}
			num.push_front(n);
		}
		else
			operator_in((*f).at(i));
		if (!xing)
			cout << num.front() << endl;
	}

}