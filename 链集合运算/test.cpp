#include<iostream>
#include"set_by_list.h"
using namespace std;

int main() {
	SetByList s1,s2,s3;
	cout << "输入s1" << endl;
	cin >> s1;
	cout <<"s1:" << s1 << endl;
	s2.add(1);
	s2.add(2);
	s2.add(6);
	cout << "s2添加了1.2.6" << endl;
	cout << "s2:" << s2 << endl;
	s3 = s1 + s2;
	cout << "s3 = s1 + s2后s3" << s3 << endl;
	SetByList s4 = s3 - s1;
	cout << "s4 = s3 - s1后s4" << s4 << endl;
	s2.add(7);
	cout << "s2添加7后s2" << s2 << endl;
	SetByList s5 = s3 * s2;
	cout << "s5 = s3 * s2" << s5 << endl;
}