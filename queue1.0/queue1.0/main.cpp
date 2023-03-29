#include"queue1.h"

    // 假设这里已经定义了 Queue 类

int main() {
    // 创建一个整数类型的队列
    Queue q;
    int n=0,a=4;
    cout << "已创建队列，输入4次整数尝试批量测试" << endl;
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