#include<iostream>
#include<vector>
#include<list>
#include <algorithm>
using namespace std;

//(1) ��ϰ vector �� list ��ʹ�á�
//����һ���յ� vector��Ԫ������Ϊ int������ 10 ����������뵽 vector �У��õ���
//������ vector ��������е�Ԫ��ֵ���� vector ͷ������һ����������õ��������� vector
//��������е�Ԫ��ֵ���÷����㷨 find ����ĳ�������������ҵ�����������򽫴���
//���� vector β�����÷����㷨 sort �� vector �����õ��������� vector ��������е�Ԫ
//��ֵ��ɾ�� vector β����Ԫ�أ��õ��������� vector ��������е�Ԫ��ֵ���� vector ��
//�ա�
//����һ�� list�����ظ�����ʵ�飬��ע��۲�����
//(2) ��ϰ�����㷨��ʹ�á�
//- 149 -
//����һ�� vector��Ԫ������Ϊ int������ 10 ���������ʹ�� sort �������������
//ÿ��Ԫ�ص�ֵ���ٰ������������ÿ��Ԫ�ص�ֵ����ϰ�� find ����Ԫ�ء��� min ��
//max �ҳ������е���СԪ�ظ����Ԫ�أ������
//
// 
// 

int main() {
	list<int> a;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++)
		a.push_back(rand() % 100);//����ʮ�������
	list<int>::iterator it;
	for (it = a.begin(); it != a.end(); it++)//����������
		cout << *it << " ";
	cout << endl;

	a.push_front(rand() % 100);//ͷ�����������
	for (it = a.begin(); it != a.end(); it++)//����������
		cout << *it << " ";
	cout << endl;

	int b= rand() % 100;
	cout<<"���������"<<b<<endl;
	if (find(a.begin(), a.end(), b) != a.end())//����find�������
		cout << "�ҵ���" << endl;
	else {
		cout << "δ�ҵ�������β��" << endl;
	 a.push_back(b);
	}
		

	a.sort();//����
	for (it = a.begin(); it != a.end(); it++)
		cout << *it << " ";
	cout << endl;

	a.pop_back();//ɾ��β��
	for (it = a.begin(); it != a.end(); it++)
		cout << *it << " ";
	cout << endl;

	a.clear();//���
	return 0;
}
