#include"a.h"
using namespace std;

/*���������ʾ���ϡ���֪��������A��B������㷨�����C = A + B����������  C = A * B����������A = A - B�����
Ҫ�������������+��*��-��=��<<���������㷨��ʱ�临�Ӷȡ��ռ临�Ӷȡ�*/
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
