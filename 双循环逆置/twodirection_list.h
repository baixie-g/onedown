#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* prev, * next;
    Node(int x=0) {
        data = x;
        prev = next = NULL;
    }
};

class DoublyLinkedList {
public:
    Node* head;/* *tail;*/
    Node headnode;
    DoublyLinkedList() {
        head  = &headnode;/*= tail*/
    }

    //����ڵ㵽ĩβ
    void insertEnd(int x) {
        Node* temp = new Node(x);
        if (headnode.prev == NULL) {
            headnode.prev = temp;/* = tail*/
            headnode.next = temp;
            temp->next = head;
            temp->prev = head;
            return;
        }
        //tail->next = temp;
        //temp->prev = tail;
        //tail = temp;
        headnode.prev->next = temp;
        temp->next = head;
        temp->prev = headnode.prev;
        headnode.prev = temp;
    }
    Node* get(int x) {
        Node* a = headnode.next;
        if (a == NULL) {
            cout << "list is vacant";
            return a;
        }
        while (x-1) {
            a = a->next;
            if (a == head)
                cout << "�ѽ�����һ��ѭ��";
            x--;
        }
        return a;
         
    }

    //����ڵ㵽��ͷ
    void insertBegin(int x) {
        Node* temp = new Node(x);
        if (headnode.next == NULL) {
            headnode.next = temp;/* = tail*/
            headnode.prev = temp;
            temp->next = &headnode;
            temp->prev = &headnode;
            return;
        }
        headnode.next->prev = temp;
        temp->prev = head;
        temp->next = headnode.next;
        headnode.next = temp;
    }

    //��ӡ����
    void display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = headnode.next;
        while (temp!=head) {
            cout << temp->data << " ";
            cout << temp << endl;
            temp = temp->next;
        }
        cout << endl;
    }

    //��ָ���Ľڵ�֮������½ڵ�
    void insertAfter(Node* prev_node, int x) {
        if (prev_node == NULL) {
            cout << "Previous node is NULL.";
            insertBegin(x);
            return;
        }
        Node* temp = new Node(x);
        temp->next = prev_node->next;
        prev_node->next = temp;
        temp->prev = prev_node;
        temp->next->prev = temp;
    }

    //ɾ��ָ���ڵ�
    void deleteNode(Node* del) {
        if (headnode.next->next == head) {
            delete headnode.next;
            headnode.next = NULL;
            headnode.prev = NULL;
            return;

        }
            
        if (head == del)
            cout << "����ͷ��㣬ɾ��һ�˰���" ;
            return;
            del->prev = del->next;
            del->next->prev = del->prev;
        delete(del);
    }
};