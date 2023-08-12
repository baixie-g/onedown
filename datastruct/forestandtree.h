#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

enum errorcode
{
	success,
	fail
};

struct TreeNode {
	char val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
	TreeNode* root=nullptr;

	TreeNode* buildtree(string& s, int& i) {
		if (s[i] == '#') {
			i++;
			return nullptr;
		}
		TreeNode* temp = new TreeNode(s[i]);
		i++;
		temp->left = buildtree(s, i);//访问用来建立node
		temp->right = buildtree(s, i);
		return temp;//返回以连接
	}

	int getHeighthelper(TreeNode* root) {
		if (!root) return 0;
		int leftHeight = getHeighthelper(root->left);
		int rightHeight = getHeighthelper(root->right);
		return max(leftHeight, rightHeight) + 1;
	}

public:
	BinaryTree(string& s) {
		root = nullptr;
	if (s.empty()) return;
		int i = 0;
		root=buildtree(s, i);
	}
	int getHeight() {
		return getHeighthelper(root);
	}
	int getheightlevel() {
		if (!root) return 0;
		queue<TreeNode*> q;
		q.push(root);
		int height = 0;
		while (!q.empty()) {
			int size = q.size();
			while (size--) {
				TreeNode* curr = q.front();
				q.pop();
				if (curr->left) {
					q.push(curr->left);
				}
				if (curr->right) {
					q.push(curr->right);
				}
			}
			height++;
		}
		return height;
	}

};
class forest {
private:
	vector<BinaryTree*> trees;
public:
	errorcode forestadd(BinaryTree* a) {
		trees.push_back(a);
		return success;
	}
	int getsize() {
		return trees.size();
	}
	int getheight() {
		int maxheight = 0;
		for (int i = 0; i < trees.size(); i++) {
			int height = trees[i]->getHeight();
			maxheight = max(maxheight, height);
		}
		return maxheight;
	}
	int getheightlevel() {
		int maxheight = 0;
		for (int i = 0; i < trees.size(); i++) {
			int height = trees[i]->getheightlevel();
			maxheight = max(maxheight, height);
		}
		return maxheight;
	}
};


