//ʵ����ҵ - 04��
//����㷨����ͷ����˫ѭ������L�͵����ã�������ԭ������Ŀռ�ʵ�����á�
//
//Ҫ�󣺽���˫ѭ������
//����ǰ�����������
//ͷ����ַ ÿ������ַ ÿ�����ֵ
//���ú����������
//ͷ����ַ ÿ������ַ ÿ�����ֵ
//
//�ڽ�ֹ��ǰ���ύ��ɹ��ܵĽ�����

#include<iostream>
//#include"twodirection_list.h"
#include"list.h"
using namespace std;

//������������
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
	//l.insert(1);//��ʵ���뺯������ͬ�ɶ���һ��
	//l.print();
	//l.insertAt(2, 2);
	//l.print();
	//l.insertAt(7,2);
	//l.print();
	//l.insertAtHead(1);
	//l.insertAtTail(99);
	//l.print();
	//l.remove(7);//ɾ������7

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