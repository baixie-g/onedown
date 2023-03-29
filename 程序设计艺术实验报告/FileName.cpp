#include<iostream>
#include<vector>
#include<list>
#include <algorithm>
using namespace std;

//(1) 练习 vector 和 list 的使用。
//定义一个空的 vector，元素类型为 int，生成 10 个随机数插入到 vector 中，用迭代
//器遍历 vector 并输出其中的元素值。在 vector 头部插入一个随机数，用迭代器遍历 vector
//并输出其中的元素值。用泛型算法 find 查找某个随机数，如果找到便输出，否则将此数
//插入 vector 尾部。用泛型算法 sort 将 vector 排序，用迭代器遍历 vector 并输出其中的元
//素值。删除 vector 尾部的元素，用迭代器遍历 vector 并输出其中的元素值。将 vector 清
//空。
//定义一个 list，并重复上述实验，并注意观察结果。
//(2) 练习泛型算法的使用。
//- 149 -
//定义一个 vector，元素类型为 int，插入 10 个随机数，使用 sort 按升序排序，输出
//每个元素的值，再按降叙排序，输出每个元素的值。练习用 find 查找元素。用 min 和
//max 找出容器中的最小元素个最大元素，并输出
//
// 
// 

int main() {
	list<int> a;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++)
		a.push_back(rand() % 100);//插入十个随机数
	list<int>::iterator it;
	for (it = a.begin(); it != a.end(); it++)//迭代器遍历
		cout << *it << " ";
	cout << endl;

	a.push_front(rand() % 100);//头部插入随机数
	for (it = a.begin(); it != a.end(); it++)//迭代器遍历
		cout << *it << " ";
	cout << endl;

	int b= rand() % 100;
	cout<<"查找随机数"<<b<<endl;
	if (find(a.begin(), a.end(), b) != a.end())//泛型find查随机数
		cout << "找到了" << endl;
	else {
		cout << "未找到，插入尾部" << endl;
	 a.push_back(b);
	}
		

	a.sort();//排序
	for (it = a.begin(); it != a.end(); it++)
		cout << *it << " ";
	cout << endl;

	a.pop_back();//删除尾部
	for (it = a.begin(); it != a.end(); it++)
		cout << *it << " ";
	cout << endl;

	a.clear();//清空
	return 0;
}
