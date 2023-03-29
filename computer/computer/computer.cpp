#include<iostream>
#include<stack>
#include<string>
using namespace std;

stack<double> num;
stack<char> ope;
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
		ope.push('#');
		xing++;
		return;
	}
			xing++;
			break; }
	case '(':
		ope.push('(');
		return;
		break;
	};
	//真，运算
	while (priority(x, ope.top())) {
		double n1 = num.top();
		num.pop();
		double n2 = num.top();
		num.pop();
		double res;
		switch (ope.top())
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
		ope.pop();
		num.push(res);
	};//x还没入栈，top是栈顶
	ope.push(x);
	if (ope.top() == ')') { ope.pop(); ope.pop(); }
}

int main() {
	cin >> *f;
	string a = *f;int n;
	for (; i < a.length(); i++) {
		if ((char)(*f).at(i) >='0') {
			n = (*f).at(i) - '0';
			if ((char)(*f).at(i - 1) >= '0'){
				n = (static_cast<int>(a.at(i - 1)) - 48) * 10 + (static_cast<int>(a.at(i)) - 48);
				num.pop();
			}
			num.push(n);
		}
		else
			operator_in((*f).at(i));
		if (!xing)
			cout << num.top() << endl;
	}

}
