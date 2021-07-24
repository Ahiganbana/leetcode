#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
    TreeNode *tree;
    //中序遍历结果
    vector<int> inorder;
    //索引中序遍历
    int index = -1;
    //二叉树中的节点个数
    int size = 0;

public:
    BSTIterator(TreeNode* root) {
        tree = root;
        inorderTraversal(root);
        size = inorder.size();
    }
    
    /** @return the next smallest number */
    int next() {
        //第一次访问
        if(index == -1) {
            index = 0;
        }else{
            index = index % size;
        }
        return inorder[index];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(index >= size - 1){
            return false;
        }else{
            return true;
        }
    }

    void inorderTraversal(TreeNode* root) {
        if(!root) {
            return;
        }
        inorderTraversal(root->left);
        inorder.push_back(root->val);
        inorderTraversal(root->right);
    }
};

class BSTIterator1 {
    stack<TreeNode *> s;

public:
    BSTIterator1(TreeNode* root) {
        _leftmostInorder(root);
    }

    void _leftmostInorder(TreeNode* root) {
        while(root) {
            s.push(root);
            root = root->left;
        }
    }

    int next() {
        TreeNode *topmostNode = s.top();
        s.pop();
        if(topmostNode->right) {
            _leftmostInorder(topmostNode->right);
        }
        return topmostNode->val;
    }

    bool hasNext() {
        return s.size() > 0;
    }
};
