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
        // 如果根节点为空，则返回0
        if (!root) {
            return 0;
        }
        // 创建一个队列来存储节点
        queue<TreeNode*> q;
        // 将根节点推入队列
        q.push(root);
        // 初始化高度为0
        int height = 0;
        // 当队列不为空时
        while (!q.empty()) {
            // 获取当前层的大小
            int size = q.size(); // size是当前层的节点数
            // 遍历当前层
            while (size--) {
                // 从队列中获取前面的节点
                TreeNode* curr = q.front();
                // 从队列中删除前面的节点
                q.pop();
                // 如果左子节点存在，则将其推入队列
                if (curr->left) {
                    q.push(curr->left);
                }
                // 如果右子节点存在，则将其推入队列
                if (curr->right) {
                    q.push(curr->right);
                }
            }
            // 增加高度
            height++;
        }
        // 返回二叉树的高度
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


