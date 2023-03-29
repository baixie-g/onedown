//实验作业 - 04：
//设计算法将带头结点的双循环链表L就地逆置，即利用原表各结点的空间实现逆置。
//
//要求：建立双循环链表；
//逆置前，正向输出：
//头结点地址 每个结点地址 每个结点值
//逆置后，正向输出：
//头结点地址 每个结点地址 每个结点值
//
//在截止日前，提交完成功能的截屏。

#include<iostream>
//#include"twodirection_list.h"
#include"list.h"
using namespace std;

//逆序整个链表
//void reverse() {
//    Node* current = head;
//    Node* temp = NULL;
//    while (current) {
//        temp = current->prev;
//        current->prev = current->next;
//        current->next = temp;
//        current = current->prev;
//    }
//    if (temp)
//        head = temp->prev;
//}

int main() {
	//DoublyLinkedList list;
	//list.insertBegin(1);
	//list.insertEnd(3);
	//list.insertAfter(list.get(1),2);
	//list.display();
	List l;
	//l.print();
	//l.insert(1);//其实插入函数均相同可独立一个
	//l.print();
	//l.insertAt(2, 2);
	//l.print();
	//l.insertAt(7,2);
	//l.print();
	//l.insertAtHead(1);
	//l.insertAtTail(99);
	//l.print();
	//l.remove(7);//删除所有7

	//l.print();
	//l.removeAt(1);
	//l.print();
	//l.reverse();
	//l.print();
	//l.quickSort(l.find(99),l.find(2));
	//l.print();

	for(int i=0;i<=4;i++)
	l.insert(i);
	l.print();
	l.reverse();
	l.print();

	return 0;
}