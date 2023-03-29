#include"a.h"
using namespace std;

/*假设链表表示集合。已知两个集合A、B，设计算法以求解C = A + B（并集），  C = A * B（交集），A = A - B（差集）
要求重载运算符，+、*、-、=、<<；并分析算法的时间复杂度、空间复杂度。*/
int main()
{
	Queue<int> q1;
	Queue<int> q2;
	Queue<int> q3;
	int n = 0, m = 0, t = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		q1.push(t);
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> t;
		q2.push(t);
	}
	q3 = q1 + q2;
	q3.print();
	q3 = q3 * q1;
	q3.print();
	q1 = q1 - q2;
	q1.print();

	return 0;
}
