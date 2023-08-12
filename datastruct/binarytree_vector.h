#include <iostream>
#include <vector>
using namespace std;

class BinaryTree {
public:
    vector<char> tree;
    int size;
    BinaryTree(string& s) {
        size = s.size();
        tree.resize(size + 1);


        for (int i = 0; i < size; i++) {
            tree[i + 1] = s[i];
        }
    }

    int getHeight() {
        if (size == 0) return 0;
        int level = 0;
        int i = 1;
        while (i <= size) {
            level++;
            i = i * 2;
        }
        return level;
    }

private:

};

