//���ö���ʵ�ִ�ӡ�������
#include <iostream>
#include <queue>
#include"queue.h"
using namespace std;
void print(int n) {
    Queue q(n+2);
    q.enqueue(1); //��һ��
    cout << 1 << endl;
    for (int i = 0; i <n; i++) { //��ӡn��
        int s = 0; //ÿ�е�һ��Ԫ��֮ǰ�ĺ�Ϊ0
        q.enqueue(s); //ÿ��ĩβ��һ��0
        for (int j = 0; j < i + 2; j++) { //��ӡÿ��i+2��Ԫ��
            int t;
            int x;
            t = q.getFront(); //ȡ������Ԫ��
            q.dequeue(); //ɾ������Ԫ��
            x = s + t; //��һ��Ԫ��Ϊ��һ����������Ԫ��֮��
            q.enqueue(x); //����һ��Ԫ�����
            cout << x << " "; //��ӡ��ǰԪ��
            s = t; //���浱ǰԪ�أ����ڼ�����һ��Ԫ��
        }
        cout << endl; //����
    }
}
int main() {
    int n;
    cin >> n;
    print(n);
    return 0;
}