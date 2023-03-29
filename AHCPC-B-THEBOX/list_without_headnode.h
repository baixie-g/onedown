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
		p = new BOX*[n];//ָ��pָ��һ�����飬����ÿһ��λ�÷���һ��BOXָ��
		for (int i = 1; i <= n; i++) {
			p[i-1] = new BOX;
			p[i-1]->data = i;
			p[i-1]->next = NULL;
		}
	}
	void M(int x,int y) {//��x���Ӷѷ���y���Ӷ���
		BOX* a;
		a = p[y-1];
		int b = p[x-1]->data;
		while (a->next != NULL) {
			a = a->next;
		}//��a��λ��y�������Ӷ��е����һ������
		a->next = p[x-1];
		p[x-1] = p[y-1];//�����ƶ����Ӷ�ԭλָ��ָ���ƶ�����λ��
		p[b - 1] = p[y - 1];
	}
	void C(int x) {//��ѯx���·����ٸ�����
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