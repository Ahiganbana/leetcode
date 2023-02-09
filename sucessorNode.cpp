// 求特殊结构的树的某一个节点的后继结点
// 后继结点指的是在中序遍历中的下一个数

#include <iostream>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode *parent;
      TreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
};


class Solution {
public:
    TreeNode* getSuccessor(TreeNode* root) {
        if(!root) {
            return nullptr;
        }

        if(root->right) {
            return getMostLeft(root->right);
        }else {
            //无右子树
            TreeNode *parent = root->parent;
            while(parent && parent->left != root) {
                root = parent;
                parent = root->parent;
            }
            return parent;
        }
    }

    TreeNode *getMostLeft(TreeNode *root) {
        if(!root) {
            return nullptr;
        }
        while(root->left) {
            root = root->left;
        }
        return root;
    }
};