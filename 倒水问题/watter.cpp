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
//��ǰˮ��current��Ŀ��ˮ��target����ǰ�������'trail'�����ս������'solution'
void BackTrack(int cup[4], int& current, int& target, vector<int>& trail, vector<int>& solution) {
	if (current == target) {
		cout << current << "����ˮ����Ŀ��" << endl;
		solution = trail;
		return;
	}
	else {
		for (int i = 0; i < 4; i++) {cout << "���Ե�" << i+1 << "����" << cup[i] << endl;
			if (cup[i] + current > target) {
				cout<<current<<"+"<<cup[i]<<"="<<cup[i]+current<<"����Ŀ��"<<target<<endl;
				continue;
			}
			else {
				trail.push_back(cup[i]);
				cout << cup[i] << "��ӽ����Խ������!!!!" << endl;
				current += cup[i];
				cout<<"����ˮ������"<<cup[i]<<"��Ϊ"<<current<<endl;
				cout<<"���⻯Ϊ"<<current<<"��"<<target<<"������"<<endl;
				BackTrack(cup, current, target, trail, solution);
				if (solution.size() != 0) {
					cout << "�ҵ��������!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					return;
				}
				cout << cup[i] << "����ʧ�ܣ�����!!!!!!!!!!!" << endl;
				current -= cup[i];
				trail.pop_back();
			}
		}
	}
}

int main(void) {
	cout << "��������A,B��Ҫװ����ˮC,ע�⣬����������������A > B:" << endl;
	int a, b, c, n;
	int volumn[4];
	cin >> a >> b >> c;
	volumn[0] = a;
	volumn[1] = b;
	volumn[2] = a - b;
	cout<<"�󱭵�С��ʣ�õ���������С"<<volumn[2]<<endl;
	for (n = 1; n * b < a; n++) {
		continue;
	}
	volumn[3] = n * b - a;
	cout<<"С������ʣ�õ����ı���С"<<volumn[3]<<endl;
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