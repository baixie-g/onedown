#include<iostream>
using namespace std;

//A 设备排列
//题目描述
//太空飞船设备间里有一排位置可以放设备。现在有 N(1≤N≤100000)
//个位置，每个位置不放设备用 0 标识，放入设备用 1 标识。但是两个设
//备（标记为 1）之间至少有 K(0≤K < N)个空位（标记为 0）。请问有多
//	少种安全的设备摆放方案。答案对 5000011 取模。
//	输入格式
//	一行，输入两个整数 N 和 K。
//	输出格式
//	一个整数(表示设备摆放的方法数，对 5000011 取模后的结果)。
//	输入样例
//	4 2
//	输出样例
//	6


int* a;
int sum = 0;
int arrange_posibility(int n,int k) {
	if (n == 1)
		return 2;
	//放在第一位
	int s = 0;
	if (a[n - 1]) {
		//cout << "被调用" << n<<"是" << a[n - 1] << endl;
return a[n - 1];
	}
		
	for (int i = 1; i <= n; i++) {
		s %= 5000011;
		if (i + k >= n)
			s++;
		else
			s+= arrange_posibility(n - k - i,k);
	}
	a[n - 1] = (s + 1)%5000011;

	//cout << "被记录" << n << "是" << a[n - 1] << endl;
	return  (s + 1) % 5000011;
}

int main() {
	int n, k;
	cin >> n >> k;
	a = new int[n]();
	sum = arrange_posibility(n, k);
	cout << sum << endl;
	delete[]a;
	return 0;
}