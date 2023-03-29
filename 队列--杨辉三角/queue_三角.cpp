//利用队列实现打印杨辉三角
#include <iostream>
#include <queue>
#include"queue.h"
using namespace std;
void print(int n) {
    Queue q(n+2);
    q.enqueue(1); //第一行
    cout << 1 << endl;
    for (int i = 0; i <n; i++) { //打印n行
        int s = 0; //每行第一个元素之前的和为0
        q.enqueue(s); //每行末尾加一个0
        for (int j = 0; j < i + 2; j++) { //打印每行i+2个元素
            int t;
            int x;
            t = q.getFront(); //取出队首元素
            q.dequeue(); //删除队首元素
            x = s + t; //下一行元素为上一行相邻两个元素之和
            q.enqueue(x); //将下一行元素入队
            cout << x << " "; //打印当前元素
            s = t; //保存当前元素，用于计算下一个元素
        }
        cout << endl; //换行
    }
}
int main() {
    int n;
    cin >> n;
    print(n);
    return 0;
}