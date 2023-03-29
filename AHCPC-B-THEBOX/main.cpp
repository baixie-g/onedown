//你好，这是Bing。我可以帮你写一个c++程序来解决这个问题。根据我的搜索结果¹²，我可以使用stack容器来存储和操作集装箱的编号。stack容器是一种后进先出（LIFO）的数据结构，它只允许在栈顶添加或删除元素。stack容器有以下几个方法：
//- push(x)：将元素x压入栈顶。
//- pop()：将栈顶元素弹出并删除。
//- top()：返回栈顶元素的引用。
//- size()：返回栈中元素的个数。
//- empty()：返回栈是否为空的布尔值。
//
//为了实现小明的指令，我需要维护一个数组，其中每个元素都是一个stack<int>类型的对象，表示一个箱堆。数组的下标就是集装箱的编号，数组的大小就是n。然后我需要遍历P个指令，对于每个指令，我需要判断它是移动还是统计，并执行相应的操作。具体来说：
//- 如果指令是Mxy，表示将x号集装箱所在的箱堆移动到y号集装箱所在的箱堆上，那么我需要先找到x号集装箱所在的位置（即它在自己所属stack中有多少个元素在它下方），然后将这些元素依次弹出并压入y号集装箱所属stack中。
//- 如果指令是Cx，表示统计x号集装箱所在的箱堆中，在x下方一共有多少集装箱，那么我只需要返回x号集装箱所属stack中除了自己以外其他元素的个数。
//
//基于以上思路，我生成了以下c++代码：
//
//```c+ +
#include <iostream>
//#include <stack>
//using namespace std;
//
//int main()
//{
//    int n, P; // n为集装箱数量，P为指令数量
//    cin >> n >> P; // 输入n和P
//    stack<int> boxes[n + 1]; // 创建一个数组boxes存储n+1个stack对象
//    for (int i = 1; i <= n; i++) // 初始化每个stack对象
//    {
//        boxes[i].push(i); // 将对应编号i压入boxes[i]中
//    }
//    for (int i = 0; i < P; i++) // 遍历P个指令
//    {
//        char op; // op为操作符
//        int x, y; // x和y为操作数
//        cin >> op >> x; // 输入op和x
//        if (op == 'M') // 如果op为M，则输入y，并执行移动操作
//        {
//            cin >> y;
//            stack<int> temp; // 创建一个临时stack对象temp用于存储要移动的元素
//            while (boxes[x].top() != x) // 找到x号集装箱所在位置，并将其下方所有元素依次弹出并压入temp中
//            {
//                temp.push(boxes[x].top());
//                boxes[x].pop();
//            }
//            boxes[y].push(boxes[x].top()); // 将x号集装箱本身也压入y号集装箱所属stack中
//            boxes[x].pop();
//            while (!temp.empty()) // 将temp中所有元素依次弹出并压入y号集装箱所属stack中
//            {
//                boxes[y].push(temp.top());
//                temp.pop();
//            }
//        }
//        else if (op == 'C') // 如果op为C，则执行统计操作，并输出结果
//        {
//            cout << boxes[x].size() - 1 << endl; // 输出除了自己以外其他元素的个数（即size()-1）
//        }
//    }
//}

#include"list_without_headnode.h"
using namespace std;
int main() {
	int n;
	cin >> n;
	char code;
	POS position = POS(n);
	while (1) {
		cin >> code;
		switch (code)
		{
		case 'M': {
			int x, y;
			cin >> x >> y;
			if(x==y)
				break;
			position.M(x, y);
		}
			break;
		case 'C': {
			int x;
			cin >> x;
			position.C(x);
		}
				break;
		}
	}

	return 0;
}