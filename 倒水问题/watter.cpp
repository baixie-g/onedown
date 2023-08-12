#include<iostream>
#include<vector>
using namespace std;

int can(int a, int b, int c);
int gcd(int a, int b);
void BackTrack(int cup[4], int& current, int& target, vector<int>& trail,
	vector<int>& solution);

int can(int a, int b, int c) {
	if (c <= 1000000000) {
		int d = gcd(a, b);
		if (c % d == 0)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}

int gcd(int a, int b) {
	if (b == 0)
		return a;
	while (b != 0) {
		int r = b;
		b = a % b;
		a = r;
	}
}
//当前水量current，目标水量target，当前解决方案'trail'和最终解决方案'solution'
void BackTrack(int cup[4], int& current, int& target, vector<int>& trail, vector<int>& solution) {
	if (current == target) {
		cout << current << "现有水就是目标" << endl;
		solution = trail;
		return;
	}
	else {
		for (int i = 0; i < 4; i++) {cout << "尝试第" << i+1 << "杯的" << cup[i] << endl;
			if (cup[i] + current > target) {
				cout<<current<<"+"<<cup[i]<<"="<<cup[i]+current<<"大于目标"<<target<<endl;
				continue;
			}
			else {
				trail.push_back(cup[i]);
				cout << cup[i] << "添加进尝试解决方案!!!!" << endl;
				current += cup[i];
				cout<<"现有水加上这"<<cup[i]<<"后为"<<current<<endl;
				cout<<"问题化为"<<current<<"和"<<target<<"的问题"<<endl;
				BackTrack(cup, current, target, trail, solution);
				if (solution.size() != 0) {
					cout << "找到解决方案!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					return;
				}
				cout << cup[i] << "尝试失败，回退!!!!!!!!!!!" << endl;
				current -= cup[i];
				trail.pop_back();
			}
		}
	}
}

int main(void) {
	cout << "输入容器A,B和要装出的水C,注意，请输入整数，而且A > B:" << endl;
	int a, b, c, n;
	int volumn[4];
	cin >> a >> b >> c;
	volumn[0] = a;
	volumn[1] = b;
	volumn[2] = a - b;
	cout<<"大杯倒小杯剩得到第三杯大小"<<volumn[2]<<endl;
	for (n = 1; n * b < a; n++) {
		continue;
	}
	volumn[3] = n * b - a;
	cout<<"小杯倒大杯剩得到第四杯大小"<<volumn[3]<<endl;
	for (int i = 0; i < 4; i++) {
		cout << volumn[i] << " ";
	}
	cout << endl;
	int current = 0;
	vector<int> trail;
	vector<int> solution;
	if (can(a, b, c)) {
		cout << "can!" << endl;
		BackTrack(volumn, current, c, trail, solution);
		for (auto i : solution) {
			cout << i << endl;
		}
	}
	else
		cout << "can't!" << endl;
	return 0;
}