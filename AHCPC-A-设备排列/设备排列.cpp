#include<iostream>
using namespace std;

//A �豸����
//��Ŀ����
//̫�շɴ��豸������һ��λ�ÿ��Է��豸�������� N(1��N��100000)
//��λ�ã�ÿ��λ�ò����豸�� 0 ��ʶ�������豸�� 1 ��ʶ������������
//�������Ϊ 1��֮�������� K(0��K < N)����λ�����Ϊ 0���������ж�
//	���ְ�ȫ���豸�ڷŷ������𰸶� 5000011 ȡģ��
//	�����ʽ
//	һ�У������������� N �� K��
//	�����ʽ
//	һ������(��ʾ�豸�ڷŵķ��������� 5000011 ȡģ��Ľ��)��
//	��������
//	4 2
//	�������
//	6


int* a;
int sum = 0;
int arrange_posibility(int n,int k) {
	if (n == 1)
		return 2;
	//���ڵ�һλ
	int s = 0;
	if (a[n - 1]) {
		//cout << "������" << n<<"��" << a[n - 1] << endl;
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

	//cout << "����¼" << n << "��" << a[n - 1] << endl;
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