#pragma once
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class List {
private:
    Node* head;
public:
    List() {
        head = new Node; // ����ͷ���
        head->data = 0;
        head->prev = head; // ǰ��ָ��ָ���Լ�
        head->next = head; // ���ָ��ָ���Լ�
    }

    ~List() {
        while (head->next != head) { // ��ͷ��ʼɾ��������Ч���
            Node* p = head->next;
            head->next = p->next;
            p->next->prev = head;
            delete p;
        }
        delete head; // ɾ��ͷ���
        head = NULL;
    }

    void insert(int x) {
        Node* p = new Node; // �����½�㲢��ֵ������Ϊx
        p->data = x;
        p->prev = head;
        p->next = head->next;
        head->next->prev = p;
        head->next = p;  // ���½����뵽ͷ���֮�󣬵�һ����Ч���֮ǰ

    }
    void insertAt(int x, int pos) { // �ڵ�pos��λ�ò���Ԫ��x
        if (pos < 1) { // ���λ�ò��Ϸ�������
            return;
        }
        Node* p = head; // ��ͷ��㿪ʼ����
        int i = 0; // ��¼��ǰλ��
        while (p->next != head && i < pos - 1) { // ���û���ҵ�β�����û�е���Ŀ��λ��
            p = p->next; // �ƶ�����һ�����
            i++; // ���µ�ǰλ��
        }
        if (i == pos - 1) { // ����ҵ���Ŀ��λ�õ�ǰһ�����
            Node* q = new Node; // �����½�㲢��ֵ������Ϊx
            q->data = x;
            q->prev = p;
            q->next = p->next;
            p->next->prev = q;
            p->next = q; // ���½����뵽p��p�ĺ��֮��
        }
    }
    void insertAtTail(int x) { // ������β������Ԫ��x
        Node *p = head->prev; // �ҵ�β���
        Node *q = new Node; // �����½�㲢��ֵ������Ϊx
        q->data = x;
        q->prev = p;
        q->next = head;
        head->prev = q;
        p->next = q; // ���½����뵽β����ͷ���֮��
    }

    void insertAtHead(int x) { // �������ײ�����Ԫ��x
        Node *p = new Node; // �����½�㲢��ֵ������Ϊx
        p->data = x;
        p->prev = head;
        p->next = head->next;
        head->next->prev = p;
        head->next = p; // ���½����뵽ͷ���͵�һ����Ч���֮��
    }


    void remove(int x) {
        Node* p = head->next; // �ӵ�һ����Ч��㿪ʼ����
        while (p != head) { // ���û���ҵ�β���
            if (p->data == x) { // ����ҵ���Ҫɾ����Ԫ��
                p->prev->next = p->next; // ����ǰ��ָ��
                p->next->prev = p->prev; // �������ָ��
                Node* q = p; // ����Ҫɾ���Ľ���ַ
                p = p->next; // �ƶ�����һ�����
                delete q; // ɾ�����
            }
            else {
                p = p->next; // �ƶ�����һ�����
            }
        }
    }

    void print() {
        Node* p = head->next; // �ӵ�һ����Ч��㿪ʼ����
        while (p != head) { // ���û���ҵ�β���
            cout << p->data <<"[" <<p<<"] "; // ��ӡ������
            p = p->next; // �ƶ�����һ�����
        }
        cout << endl;
    }

    void reverse() { // �������е����н���ͷָ���βָ�뻥��
        Node* p = head; // ��ͷ��㿪ʼ����
        do {
            Node* q = p->prev; // ����ǰ��ָ��
            p->prev = p->next; // ��ǰ��ָ�뻻�ɺ��ָ��
            p->next = q; // �����ָ�뻻��ǰ��ָ��
            p = p->prev; // �ƶ�����һ����㣨ԭ���ĺ�̽�㣩
        } while (p != head); // ���û�лص�ͷ��㣬����ѭ��
    } 
    void removeAt(int pos) { // ɾ����pos��λ�õĽ��
        if (pos < 1) { // ���λ�ò��Ϸ�������
            return;
        }
        Node *p = head; // ��ͷ��㿪ʼ����
        int i = 0; // ��¼��ǰλ��
        while (p->next != head && i < pos - 1) { // ���û���ҵ�β�����û�е���Ŀ��λ�õ�ǰһ�����
            p = p->next; // �ƶ�����һ�����
            i++; // ���µ�ǰλ��
        }
        if (i == pos - 1 && p->next != head) { // ����ҵ���Ŀ��λ�õ�ǰһ�������Ŀ��λ�ò���β���
            Node *q = p->next; // ����Ҫɾ���Ľ���ַ
            p->next = q->next; // ����ǰ��ָ��
            q->next->prev = p; // �������ָ��
            delete q; // ɾ�����
        }
    }

    void sort() { // �������е�������Ч��������������ʹ�ÿ��������㷨��
        quickSort(head->next, head->prev); // ���ÿ��������������������һ����Ч�������һ����Ч�����Ϊ����
    }

    void quickSort(Node *left, Node *right) { // ������������������[left,right]�����ڵĽ��������򣨰������ұ߽磩
        if (left == right || left == right->next) { 
            return;  
        }
        Node* pivot = left; // ѡ����߽���Ϊ��׼Ԫ��
        Node* p = left->next; // ����߽����һ����㿪ʼ����
        Node* q = right; // ���ұ߽翪ʼ����
        while (p != q) { // ���û������
            while (p != q && p->data <= pivot->data) { // ���pָ��Ľ���������С�ڵ��ڻ�׼Ԫ�أ���û������
                p = p->next; // �ƶ�����һ�����
            }
            while (p != q && q->data >= pivot->data) { // ���qָ��Ľ�����������ڵ��ڻ�׼Ԫ�أ���û������
                q = q->prev; // �ƶ�����һ�����
            }
            if (p != q) { // ���û������������p��qָ��Ľ���������
                int temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
        if (pivot->data > p->data) { // �����׼Ԫ�ش�����������Ľ��������򣬽������ǵ�������
            int temp = pivot->data;
            pivot->data = p->data;
            p->data = temp;
        }
        quickSort(left, p->prev); // ��[left,p-1]�����ڵĽ��������򣨲������ұ߽磩
        quickSort(p->next, right); // ��[p+1,right]�����ڵĽ��������򣨲�������߽磩
    } 

    Node * find(int x) { // ���������е�һ��������Ϊx�Ľ���ָ�룬���û���ҵ�������nullptr
        Node* p = head->next; // �ӵ�һ����Ч��㿪ʼ����
        while (p != head) { // ���û�лص�ͷ���
            if (p->data == x) { // ����ҵ���Ŀ��Ԫ��
                return p; // ���ظý���ָ��
            }
            p = p->next; // �ƶ�����һ�����
        }
        return nullptr; // ����������û���ҵ������ؿ�ָ��
    }

    Node* get(int pos) { // ���������е�pos��λ�õĽ���ָ�룬���λ�ò��Ϸ�������nullptr
        if (pos < 1) { // ���λ�ò��Ϸ������ؿ�ָ��
            return nullptr;
        }
        Node* p = head; // ��ͷ��㿪ʼ����
        int i = 0; // ��¼��ǰλ��
        while (p->next != head && i < pos) { // ���û���ҵ�β�����û�е���Ŀ��λ��
            p = p->next; // �ƶ�����һ�����
            i++; // ���µ�ǰλ��
        }
        if (i == pos) { // ����ҵ���Ŀ��λ�õĽ��
            return p; // ���ظý���ָ��õģ��Ҽ���д���롣�뿴���²��֣�
        }
        return nullptr; // ���û���ҵ�Ŀ��λ�õĽ�㣬���ؿ�ָ��
    }

};


