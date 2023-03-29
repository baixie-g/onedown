#include<iostream>
#include<thread>
using namespace std;

//(2) �˻ʺ����⣺
//��һ���������������ϷŰ˸��ʺ�ʹ���κ������ʺ�֮�䲻�໥�������������
//�Ĳ��巽�����ϻ����в���������
//˼�����������ƹ㵽 N �ʺ������������� N �Ƚϴ������£��ȷ�˵ N = 16 ��ʱ
//����ĳ����ܷ���ٵ���������������ܣ�˼����ʲô�����ܹ��Ż��㷨

//����һ��ȫ�ֱ�����������¼��ĸ���
int sum = 0;

//�жϵ�ǰλ���Ƿ���Է��ûʺ�
bool isOk(int row, int col, int* result)
{
	int leftup = col - 1;
	int rightup = col + 1;
	for (int i = row - 1; i >= 0; --i)
	{
		if (result[i] == col) return false;
		if (leftup >= 0)
		{
			if (result[i] == leftup) return false;
		}
		if (rightup < 8)
		{
			if (result[i] == rightup) return false;
		}
		--leftup;
		++rightup;
	}
	return true;
}

//��ӡ���
void print(int* result)
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (result[i] == j)
				cout << "Q ";
			else
				cout << "* ";
		}
		cout << endl;
	}
	cout << endl;
}

//���ûʺ�
void cal8queens(int row, int* result)
{
	if (row == 8)
	{
		print(result);
		++sum;
		return;
	}
	for (int col = 0; col < 8; ++col)
	{
		if (isOk(row, col, result))
		{
			result[row] = col;
			cal8queens(row + 1, result);
		}
	}
}

int main()
{
	int result[8] = { 0 };
	cal8queens(0, result);
	cout << sum << endl;
	return 0;
}
