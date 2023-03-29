#pragma once
#include<iostream>
using namespace std;

struct BOX {
	int data;
	BOX* next;
};

class POS {
public:
	BOX** p;
	POS(int n) {
		p = new BOX*[n];//指针p指向一个数组，数组每一个位置放着一个BOX指针
		for (int i = 1; i <= n; i++) {
			p[i-1] = new BOX;
			p[i-1]->data = i;
			p[i-1]->next = NULL;
		}
	}
	void M(int x,int y) {//把x箱子堆放在y箱子堆上
		BOX* a;
		a = p[y-1];
		int b = p[x-1]->data;
		while (a->next != NULL) {
			a = a->next;
		}//将a定位到y所在箱子堆中的最后一个箱子
		a->next = p[x-1];
		p[x-1] = p[y-1];//将被移动箱子堆原位指针指向移动到的位置
		p[b - 1] = p[y - 1];
	}
	void C(int x) {//查询x箱下方多少个箱子
		int i = 0;
		BOX* a = p[x-1];
		while (a->data != x) {
			i++;
			a = a->next;
		}
		cout << i << endl;
		return;
	}
};