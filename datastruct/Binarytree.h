#pragma once
//��Ʋ�ʵ�ֶ������ࡣ��Ҫ���Ƕ������Ľ�������ģ�顣
//�������Ľ�������ģ���������������������ն��������ж϶������Ƿ�Ϊ�ա�
//�����������ȡ����������Ҷ�ӽ��������������Ľ��������������Ķȡ�
//��������Ŀ�ȡ���������ĸ���㡢��������ĸ���㡢������������ӽ�㡢
//����������Һ��ӽ�㡢����������ֵܽ�㡢��������Ľ��ֵ��
//��������Ľ��Ĳ�Ρ���������Ľ���λ�á�
//��������Ľ�������������������Ľ�����������
//��������Ľ���������������������Ľ��������ֵܽ�㡢
//��������Ľ������������ĸ߶ȡ���������Ľ������������Ŀ�ȡ�
//��������Ľ������������Ľ��������������Ľ�������������Ҷ�ӽ������
//��������Ľ������������Ķȡ���������Ľ������������ĸ���㡢
//��������Ľ������������ĸ���㡢��������Ľ����������������ӽ�㡢
//��������Ľ��������������Һ��ӽ�㡢��������Ľ��������������ֵܽ�㡢

//��������Ľ������������Ľ��ֵ����������Ľ������������Ľ��Ĳ�Ρ�

#include<iostream>
#include<queue>
using namespace std;
//
//template<class T>
//class Tree
//{
//private:
//	struct Node
//	{
//		T data;
//		Node *left;
//		Node *right;
//	public:
//		Node(T x, Node* l = NULL, Node* r = NULL)
//		{
//			data = x;
//			left = l;
//			right = r;
//		}
//	};
//	Node *root;
//	public:
//		Tree();
//		~Tree();
//		void CreateTree();
//		void ClearTree();
//		bool IsEmpty();
//		int Depth();
//		int LeafNum();
//		int NodeNum();
//		int Degree();
//		int Width();
//		T Root();
//		T Parent(T x);
//		T LeftChild(T x);
//		T RightChild(T x);
//		T Brother(T x);
//		T Value(T x);
//		int Level(T x);
//		int Position(T x);
//		Tree LeftSubTree(T x);
//		Tree RightSubTree(T x);
//		Tree LeftRightSubTree(T x);
//		Tree LeftRightBrother(T x);
//		int LeftHeight(T x);
//		int RightHeight(T x);
//		int LeftWidth(T x);
//		int RightWidth(T x);
//		int LeftNodeNum(T x);
//		int RightNodeNum(T x);
//		int LeftLeafNum(T x);
//		int RightLeafNum(T x);
//		int LeftDegree(T x);
//		int RightDegree(T x);
//		T LeftRoot(T x);
//		T RightRoot(T x);
//		T LeftParent(T x);
//		T RightParent(T x);
//		T LeftLeftChild(T x);
//		T RightRightChild(T x);
//		T LeftRightChild(T x);
//		T RightLeftChild(T x);
//		T LeftBrother(T x);
//		T RightBrother(T x);
//		T LeftValue(T x);
//		T RightValue(T x);
//		int LeftLevel(T x);
//		int RightLevel(T x);
//		void PreOrder();
//		void InOrder();
//		void PostOrder();
//		void LevelOrder();
//		void PreOrder(Node *p);
//		void InOrder(Node *p);
//		void PostOrder(Node *p);
//		void LevelOrder(Node *p);
//		void CreateTree(Node *&p);
//		void ClearTree(Node *&p);
//		bool IsEmpty(Node *p);
//		int Depth(Node *p);
//		int LeafNum(Node *p);
//		int NodeNum(Node *p);
//		int Degree(Node *p);
//		int Width(Node *p);
//		T Root(Node *p);
//		T Parent(Node *p, T x);
//		T LeftChild(Node *p, T x);
//		T RightChild(Node *p, T x);
//		T Brother(Node *p, T x);
//		T Value(Node *p, T x);
//		int Level(Node *p, T x);
//		int Position(Node *p,)
//};

class BinaryTree {
private:
    struct Node {
        char data;
        Node* left;
        Node* right;
        Node(char val) : data(val), left(nullptr), right(nullptr) {}
    };
    Node* root;//ͷָ�뻹��ͷ��㣿
public:
    BinaryTree() : root(nullptr) {}
    Node* getRoot() {
		return root;
	}
    //ƽ�����������
    void insert(int val) {
        Node* newNode = new Node(val);
        if (root == nullptr) {
            root = newNode;
            return;
        }
        Node* curr = root;
        while (true) {
            if (val < curr->data) {
                if (curr->left == nullptr) {
                    curr->left = newNode;
                    return;
                }
                curr = curr->left;
            }
            else {
                if (curr->right == nullptr) {
                    curr->right = newNode;
                    return;
                }
                curr = curr->right;
            }
        }
    }
    //��ƽ�������
    void insert2(int val) {
        if (root == NULL) {
            root = new Node(val);
            return;
        }
        Node* cur = root;
        int level = 1;
        while (cur->left != NULL && cur->right != NULL) {
            if (val <= cur->data) {
                cur = cur->left;
            }
            else {
                cur = cur->right;
            }
            level++;
        }
        if (cur->left == NULL) {
            cur->left = new Node(val);
        }
        else {
            cur->right = new Node(val);
        }
    }
    //������ȫ������
    void insertdisorder(int var) {
        if (root == NULL) {
            root = new Node(var);
            return;
        }
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            if (curr->left == NULL) {
                curr->left = new Node(var);
                return;
            }
            else {
                q.push(curr->left);
            }
            if (curr->right == NULL) {
                curr->right = new Node(var);
                return;
            }
            else {
                q.push(curr->right);
            }
        }
    }
    //��չ������������
    void preordercreate(Node*& temp) {
        char c;
        cin >> c;
        if (c == '#')
            temp = nullptr;
        else {
            temp = new Node(c);
            preordercreate(temp->left);
            preordercreate(temp->right);
        }
    }

    int getHeight() {
        return getHeightHelper(root);
    }
    int getHeightHelper(Node* curr) {
        if (curr == nullptr) {
			return 0;
		}
		int leftHeight = getHeightHelper(curr->left);
		int rightHeight = getHeightHelper(curr->right);
		return 1 + max(leftHeight, rightHeight);
	}

    void printAll() {
        cout << "(";
        printAllHelper(root);
        cout << ")";
    }
    void printAllHelper(Node* curr) {
        if (curr == nullptr) {
            return;
        }
        printAllHelper(curr->left);
        cout << curr->data << " ";
        printAllHelper(curr->right);
    }

    void printPreOrder() {
        std::cout << "(";
        printPreOrderHelper(root);
        std::cout << ")";
    }
    void printPreOrderHelper(Node* curr) {
        if (curr == nullptr) {
            return;
        }
        cout << curr->data << " ";
        printPreOrderHelper(curr->left);
        printPreOrderHelper(curr->right);
    }

    void printInOrder() {
		printInOrderHelper(root);
	}
    void printInOrderHelper(Node* curr) {
        if (curr == nullptr) {
			return;
		}
        cout << "(";
		printInOrderHelper(curr->left);
		cout << curr->data;
		printInOrderHelper(curr->right);
        cout << ")";
	}

    void printPaths(Node* node, string path, int length) {
        if (node == nullptr) {
            return;
        }
        // Add current node to path
        path += " ";
        path += node->data;
        length++;
        // If leaf node, print path and length
        if (node->left == nullptr && node->right == nullptr) {
            cout << "Path: " << path << ", Length: " << length << endl;
        }
        // Recursively traverse left and right subtrees
        printPaths(node->left, path, length);
        printPaths(node->right, path, length);
    }

};