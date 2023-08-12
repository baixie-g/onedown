#include <iostream>
#include <string>
#include <vector>
#include<queue>
using namespace std;

struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    TreeNode* buildTree(string& s) {
        if (s.empty()) return nullptr;
        int i = 0;
        return buildTree(s, i);
    }
    

    void printLeafPaths(TreeNode* root) {
        vector<char> path;
        vector<int> pathLen;
        printLeafPaths(root, path, pathLen);
    }
    int getHeight_recursion(TreeNode* root) {
        if (!root) return 0;
        int leftHeight = getHeight_recursion(root->left);
        int rightHeight = getHeight_recursion(root->right);
        return max(leftHeight, rightHeight) + 1;
    }

    int getHeight_level(TreeNode* root) {
        // ������ڵ�Ϊ�գ��򷵻�0
        if (!root) {
            return 0;
        }
        // ����һ���������洢�ڵ�
        queue<TreeNode*> q;
        // �����ڵ��������
        q.push(root);
        // ��ʼ���߶�Ϊ0
        int height = 0;
        // �����в�Ϊ��ʱ
        while (!q.empty()) {
            // ��ȡ��ǰ��Ĵ�С
            int size = q.size(); // size�ǵ�ǰ��Ľڵ���
            // ������ǰ��
            while (size--) {
                // �Ӷ����л�ȡǰ��Ľڵ�
                TreeNode* curr = q.front();
                // �Ӷ�����ɾ��ǰ��Ľڵ�
                q.pop();
                // ������ӽڵ���ڣ������������
                if (curr->left) {
                    q.push(curr->left);
                }
                // ������ӽڵ���ڣ������������
                if (curr->right) {
                    q.push(curr->right);
                }
            }
            // ���Ӹ߶�
            height++;
        }
        // ���ض������ĸ߶�
        return height;
    }

private:
    void printLeafPaths(TreeNode* root, vector<char>& path, vector<int>& pathLen) {
        if (!root) return;
        if (!root->left && !root->right) {
            for (int i = 0; i < path.size(); ++i)
                cout << path[i] << " ";
            cout << root->val << " ";
            pathLen.push_back(path.size() + 1);
            cout << "length: " << path.size()<< endl;
            return;
        }
        path.push_back(root->val);
        printLeafPaths(root->left, path, pathLen);
        printLeafPaths(root->right, path, pathLen);
        path.pop_back();
    }

    TreeNode* buildTree(string& s, int& i) {
        if (i >= s.size() || s[i] == '#') {
            ++i;
            return nullptr;
        }
        auto root = new TreeNode(s[i++]);
        root->left = buildTree(s, i);
        root->right = buildTree(s, i);
        return root;
    }
};


