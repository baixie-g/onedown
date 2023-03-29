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
        head = new Node; // 创建头结点
        head->data = 0;
        head->prev = head; // 前驱指针指向自己
        head->next = head; // 后继指针指向自己
    }

    ~List() {
        while (head->next != head) { // 从头开始删除所有有效结点
            Node* p = head->next;
            head->next = p->next;
            p->next->prev = head;
            delete p;
        }
        delete head; // 删除头结点
        head = NULL;
    }

    void insert(int x) {
        Node* p = new Node; // 创建新结点并赋值数据域为x
        p->data = x;
        p->prev = head;
        p->next = head->next;
        head->next->prev = p;
        head->next = p;  // 将新结点插入到头结点之后，第一个有效结点之前

    }
    void insertAt(int x, int pos) { // 在第pos个位置插入元素x
        if (pos < 1) { // 如果位置不合法，返回
            return;
        }
        Node* p = head; // 从头结点开始遍历
        int i = 0; // 记录当前位置
        while (p->next != head && i < pos - 1) { // 如果没有找到尾结点且没有到达目标位置
            p = p->next; // 移动到下一个结点
            i++; // 更新当前位置
        }
        if (i == pos - 1) { // 如果找到了目标位置的前一个结点
            Node* q = new Node; // 创建新结点并赋值数据域为x
            q->data = x;
            q->prev = p;
            q->next = p->next;
            p->next->prev = q;
            p->next = q; // 将新结点插入到p和p的后继之间
        }
    }
    void insertAtTail(int x) { // 在链表尾部插入元素x
        Node *p = head->prev; // 找到尾结点
        Node *q = new Node; // 创建新结点并赋值数据域为x
        q->data = x;
        q->prev = p;
        q->next = head;
        head->prev = q;
        p->next = q; // 将新结点插入到尾结点和头结点之间
    }

    void insertAtHead(int x) { // 在链表首部插入元素x
        Node *p = new Node; // 创建新结点并赋值数据域为x
        p->data = x;
        p->prev = head;
        p->next = head->next;
        head->next->prev = p;
        head->next = p; // 将新结点插入到头结点和第一个有效结点之间
    }


    void remove(int x) {
        Node* p = head->next; // 从第一个有效结点开始遍历
        while (p != head) { // 如果没有找到尾结点
            if (p->data == x) { // 如果找到了要删除的元素
                p->prev->next = p->next; // 调整前驱指针
                p->next->prev = p->prev; // 调整后继指针
                Node* q = p; // 保存要删除的结点地址
                p = p->next; // 移动到下一个结点
                delete q; // 删除结点
            }
            else {
                p = p->next; // 移动到下一个结点
            }
        }
    }

    void print() {
        Node* p = head->next; // 从第一个有效结点开始遍历
        while (p != head) { // 如果没有找到尾结点
            cout << p->data <<"[" <<p<<"] "; // 打印数据域
            p = p->next; // 移动到下一个结点
        }
        cout << endl;
    }

    void reverse() { // 将链表中的所有结点的头指针和尾指针互换
        Node* p = head; // 从头结点开始遍历
        do {
            Node* q = p->prev; // 保存前驱指针
            p->prev = p->next; // 将前驱指针换成后继指针
            p->next = q; // 将后继指针换成前驱指针
            p = p->prev; // 移动到下一个结点（原来的后继结点）
        } while (p != head); // 如果没有回到头结点，继续循环
    } 
    void removeAt(int pos) { // 删除第pos个位置的结点
        if (pos < 1) { // 如果位置不合法，返回
            return;
        }
        Node *p = head; // 从头结点开始遍历
        int i = 0; // 记录当前位置
        while (p->next != head && i < pos - 1) { // 如果没有找到尾结点且没有到达目标位置的前一个结点
            p = p->next; // 移动到下一个结点
            i++; // 更新当前位置
        }
        if (i == pos - 1 && p->next != head) { // 如果找到了目标位置的前一个结点且目标位置不是尾结点
            Node *q = p->next; // 保存要删除的结点地址
            p->next = q->next; // 调整前驱指针
            q->next->prev = p; // 调整后继指针
            delete q; // 删除结点
        }
    }

    void sort() { // 对链表中的所有有效结点进行升序排序（使用快速排序算法）
        quickSort(head->next, head->prev); // 调用快速排序辅助函数，传入第一个有效结点和最后一个有效结点作为参数
    }

    void quickSort(Node *left, Node *right) { // 快速排序辅助函数，对[left,right]区间内的结点进行排序（包含左右边界）
        if (left == right || left == right->next) { 
            return;  
        }
        Node* pivot = left; // 选择左边界作为基准元素
        Node* p = left->next; // 从左边界的下一个结点开始遍历
        Node* q = right; // 从右边界开始遍历
        while (p != q) { // 如果没有相遇
            while (p != q && p->data <= pivot->data) { // 如果p指向的结点的数据域小于等于基准元素，且没有相遇
                p = p->next; // 移动到下一个结点
            }
            while (p != q && q->data >= pivot->data) { // 如果q指向的结点的数据域大于等于基准元素，且没有相遇
                q = q->prev; // 移动到上一个结点
            }
            if (p != q) { // 如果没有相遇，交换p和q指向的结点的数据域
                int temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
        if (pivot->data > p->data) { // 如果基准元素大于最后相遇的结点的数据域，交换它们的数据域
            int temp = pivot->data;
            pivot->data = p->data;
            p->data = temp;
        }
        quickSort(left, p->prev); // 对[left,p-1]区间内的结点进行排序（不包含右边界）
        quickSort(p->next, right); // 对[p+1,right]区间内的结点进行排序（不包含左边界）
    } 

    Node * find(int x) { // 返回链表中第一个数据域为x的结点的指针，如果没有找到，返回nullptr
        Node* p = head->next; // 从第一个有效结点开始遍历
        while (p != head) { // 如果没有回到头结点
            if (p->data == x) { // 如果找到了目标元素
                return p; // 返回该结点的指针
            }
            p = p->next; // 移动到下一个结点
        }
        return nullptr; // 如果遍历完毕没有找到，返回空指针
    }

    Node* get(int pos) { // 返回链表中第pos个位置的结点的指针，如果位置不合法，返回nullptr
        if (pos < 1) { // 如果位置不合法，返回空指针
            return nullptr;
        }
        Node* p = head; // 从头结点开始遍历
        int i = 0; // 记录当前位置
        while (p->next != head && i < pos) { // 如果没有找到尾结点且没有到达目标位置
            p = p->next; // 移动到下一个结点
            i++; // 更新当前位置
        }
        if (i == pos) { // 如果找到了目标位置的结点
            return p; // 返回该结点的指针好的，我继续写代码。请看以下部分：
        }
        return nullptr; // 如果没有找到目标位置的结点，返回空指针
    }

};


