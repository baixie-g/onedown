#include"queue1.h"

    // ���������Ѿ������� Queue ��

int main() {
    // ����һ���������͵Ķ���
    Queue q;
    int n=0,a=4;
    cout << "�Ѵ������У�����4������������������" << endl;
    while (a)
    {
        cin >> n;
        if(n<0)
        for (int i = 0; i < -n; i++) {
            q.dequeue();
            q.printQueue();
        }
        else
            for (int i = 0; i < n; i++) {
                q.enqueue(i);
                q.printQueue();
            }
        a--;
    }
}