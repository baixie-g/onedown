#include<iostream>
#include<thread>
using namespace std;

//(2) 八皇后问题：
//在一个国际象棋棋盘上放八个皇后，使得任何两个皇后之间不相互攻击，求出所有
//的布棋方法。上机运行并检验结果。
//思考：将此题推广到 N 皇后的情况，检验在 N 比较大的情况下，比方说 N = 16 的时
//候，你的程序能否快速的求出结果，如果不能，思考有什么方法能够优化算法

//定义一个全局变量，用来记录解的个数
int sum = 0;

//判断当前位置是否可以放置皇后
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

//打印结果
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

//放置皇后
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
