#pragma once
#include"binarytreenode.h"
#include<iostream>

using namespace std;

class forest{
	public:
	vector<TreeNode*> trees;
	int size;
	forest(string& s) {
		size = s.size();
		trees.resize(size + 1);
		for (int i = 0; i < size; i++) {
			trees[i + 1] = new TreeNode(s[i]);
		}
	}
	void buildTree(string& s) {
		if (s.empty()) return;
		buildTree(s);
	}
	int forest_getHeight_level() {
		int maxHeight = 0;
		for (int i = 1; i <= size; i++) {
			int height = trees[i].getHeight_level();
			maxHeight = max(maxHeight, height);
		}
		return maxHeight;
	}
	int getHeight_level_helper(TreeNode* a) {
		
	}
};