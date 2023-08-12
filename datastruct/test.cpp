#include<iostream>
//#include"Binarytree.h"
//#include"binarytreenode.h"
//#include"forest.h"
#include"forestandtree.h"
//#include"binarytree_vector.h"
using namespace std;
int main() {
	string s = "AB###";
	BinaryTree* a = new BinaryTree(s);
	string s1 = "ABC###DEFG#####";
	BinaryTree* b = new BinaryTree(s1);
	string s2 = "ABC###DEFG####H##";
	BinaryTree* c = new BinaryTree(s2);
	forest* f = new forest();
	f->forestadd(a);
	f->forestadd(b);
	f->forestadd(c);
	cout << f->getsize() << endl;
	cout << f->getheight() << endl;
	cout << f->getheightlevel() << endl;
	return 0;
}
//
//int main() {
//	string a = "AB##CDE####";
//	BinaryTree bt;
//	TreeNode* root = bt.buildTree(a);
//	bt.printLeafPaths(root);
//	cout << bt.getHeight_recursion(root) << endl;
//	cout << bt.getHeight_level(root) << endl;
//	return 0;
//}	
//string a = "AB##CDE####";
//	BinaryTree bt(a);
//	cout << endl;
//	cout << bt.getHeight() << endl;
//
//
//	return 0;
//	